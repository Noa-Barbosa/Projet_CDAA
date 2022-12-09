#include "gestionnaireBDD.h"

GestionnaireBDD::GestionnaireBDD(const QString& path)
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (!db.open())
    {
        qDebug() << "Erreur de connexion avec la BDD";
    }
    else
    {
        qDebug() << "Connexion etablie avec la BDD";

        QSqlQuery query(db);
        //cette requete active les contraintes de cle etrangeres qui par defaut sont desactivees
        query.exec("PRAGMA foreign_keys = ON;");

        hydrateContactList();
        hydrateInteractionList();
        hydrateTodoList();
        hydrateContactInteractionList();
        hydrateInteractionTodoList();
    }


}

void GestionnaireBDD::beginTransaction()
{
    QSqlQuery query(db);
    query.exec("begin;");
}

void GestionnaireBDD::rollbackTransaction()
{
    QSqlQuery query(db);
    query.exec("rollback;");
}

const list<ContactEntity *> &GestionnaireBDD::getListContactEntity() const
{
    return listContactEntity;
}

void GestionnaireBDD::setListContactEntity(const list<ContactEntity *> &newListContactEntity)
{
    listContactEntity = newListContactEntity;
}

const list<InteractionEntity *> &GestionnaireBDD::getListInteractionEntity() const
{
    return listInteractionEntity;
}

void GestionnaireBDD::setListInteractionEntity(const list<InteractionEntity *> &newListInteractionEntity)
{
    listInteractionEntity = newListInteractionEntity;
}

const list<TodoEntity *> &GestionnaireBDD::getListTodoEntity() const
{
    return listTodoEntity;
}

void GestionnaireBDD::setListTodoEntity(const list<TodoEntity *> &newListTodoEntity)
{
    listTodoEntity = newListTodoEntity;
}

const list<ContactInteractionEntity *> &GestionnaireBDD::getListContactInteractionEntity() const
{
    return listContactInteractionEntity;
}

void GestionnaireBDD::setListContactInteractionEntity(const list<ContactInteractionEntity *> &newListContactInteractionEntity)
{
    listContactInteractionEntity = newListContactInteractionEntity;
}

const list<InteractionTodoEntity *> &GestionnaireBDD::getListInteractionTodoEntity() const
{
    return listInteractionTodoEntity;
}

void GestionnaireBDD::setListInteractionTodoEntity(const list<InteractionTodoEntity *> &newListInteractionTodoEntity)
{
    listInteractionTodoEntity = newListInteractionTodoEntity;
}

bool GestionnaireBDD::isContactInList(ContactEntity *contactRecherche)
{
    list<ContactEntity*>::iterator findIter = find(listContactEntity.begin(), listContactEntity.end(), contactRecherche);

    if(findIter!=listContactEntity.end()){
        return true;
    }
    else{
        return false;
    }
}

bool GestionnaireBDD::isInteractionInList(InteractionEntity *interactionRecherche)
{
    list<InteractionEntity*>::iterator findIter = find(listInteractionEntity.begin(), listInteractionEntity.end(), interactionRecherche);

    if(findIter!=listInteractionEntity.end()){
        return true;
    }
    else{
        return false;
    }

}

bool GestionnaireBDD::isTodoInList(TodoEntity *todoRecherche)
{
    list<TodoEntity*>::iterator findIter = find(listTodoEntity.begin(), listTodoEntity.end(), todoRecherche);

    if(findIter!=listTodoEntity.end()){
        return true;
    }
    else{
        return false;
    }
}

bool GestionnaireBDD::isContactInteractionInList(ContactInteractionEntity *contactInteractionRecherche)
{
    list<ContactInteractionEntity*>::iterator findIter = find(listContactInteractionEntity.begin(), listContactInteractionEntity.end(), contactInteractionRecherche);

    if(findIter!=listContactInteractionEntity.end()){
        return true;
    }
    else{
        return false;
    }
}

bool GestionnaireBDD::isInteractionTodoInList(InteractionTodoEntity *interactionTodoRecherche)
{
    list<InteractionTodoEntity*>::iterator findIter = find(listInteractionTodoEntity.begin(), listInteractionTodoEntity.end(), interactionTodoRecherche);

    if(findIter!=listInteractionTodoEntity.end()){
        return true;
    }
    else{
        return false;
    }
}

bool GestionnaireBDD::hydrateContactList()
{
    listContactEntity.clear();
    QSqlQuery query(db);

    //si query.exec renvoie false cela signifie qu'il y a eu une erreur au moment de l'execution de la requete
    if(!query.exec("SELECT idContact, nomContact, prenomContact, entrepriseContact, uriPhotoContact, mailContact, telContact, dateCreaContact, dateDernModifContact FROM Contact")){
        cerr << "Erreur lors de la selection des contacts dans la BDD "<<query.lastError().text().toStdString() << endl;
        return false;
    }else{
        try {
            while(query.next()){

                //recupere la chaine de caractere correspondant au numero de telephone
                //convertit chacun des caractere en unsigned int et les stocke dans une liste
                list<unsigned>  tel;
                for (char &chiffre : query.value(6).toString().toStdString()) {
                        tel.push_back((unsigned) chiffre - '0');
                    }

                //cette partie du code separe la chaine de caractere donne la date de creation en trois parties et la stocke dans un vector
                std::vector<std::string> partiesDate;
                std::string partie;
                std::istringstream dateStream(query.value(7).toString().toStdString());
                while (std::getline(dateStream, partie, '-'))
                {
                   partiesDate.push_back(partie);
                }

                //convertit chacune des trois parties de la date en entier
                int annee = std::stoi(partiesDate.at(0));
                int mois = std::stoi(partiesDate.at(1));
                int jour = std::stoi(partiesDate.at(2));

                //pour creer la date approprie
                year_month_day dateCrea =year{annee}/mois/jour;

                //cette partie fait la meme chose avec la date de derniere modification
                partiesDate.clear();
                std::istringstream dateStream2(query.value(7).toString().toStdString());
                while (std::getline(dateStream2, partie, '-'))
                {
                   partiesDate.push_back(partie);
                }

                annee = std::stoi(partiesDate.at(0));
                mois = std::stoi(partiesDate.at(1));
                jour = std::stoi(partiesDate.at(2));

                year_month_day dateDernModif =year{annee}/mois/jour;

                int id = query.value(0).toInt();
                string nom = query.value(1).toString().toStdString();
                string prenom = query.value(2).toString().toStdString();
                string entreprise = query.value(3).toString().toStdString();
                string uriPhoto = query.value(4).toString().toStdString();
                string mail = query.value(5).toString().toStdString();

                ContactEntity* Contact = new ContactEntity(id, nom, prenom, entreprise, mail, tel,uriPhoto, dateCrea, dateDernModif);

                listContactEntity.push_back(Contact);
            }

            cout << "Liste des contacts mis a jour avec succes" << endl;
            return true;

        } catch (const exception & e) {
            cerr <<"Erreur lors du remplissage de la liste contact" << e.what() << endl;
            return false;
        }

    }

}

bool GestionnaireBDD::insertContact(ContactEntity *contact)
{
    try {
        QSqlQuery insertQuery(db);
        insertQuery.prepare("INSERT INTO Contact (nomContact, prenomContact, entrepriseContact, uriPhotoContact, mailContact, telContact, dateCreaContact, dateDernModifContact) "
                      "VALUES (:nomContact, :prenomContact, :entrepriseContact, :uriPhotoContact, :mailContact, :telContact, :dateCreaContact, :dateDernModifContact)");

        //on recupere chacune des valeurs string depuis l'objet en parametre pour les binds
        insertQuery.bindValue(":nomContact", QString::fromStdString(contact->getNomContact()));
        insertQuery.bindValue(":prenomContact", QString::fromStdString(contact->getPrenomContact()));
        insertQuery.bindValue(":entrepriseContact", QString::fromStdString(contact->getEntrepriseContact()));
        insertQuery.bindValue(":uriPhotoContact", QString::fromStdString(contact->getPhotoContact()));
        insertQuery.bindValue(":mailContact", QString::fromStdString(contact->getMailContact()));

        //pour le numero de telephone il faut envoyer chacun des chiffres dans un stream qu'on convertit ensuite en string
        list<unsigned> listeNumeros = contact->getTelContact();
        stringstream streamChiffres;
        string tel;
        for (unsigned &chiffre : listeNumeros){
            streamChiffres << chiffre;
        }
        streamChiffres >> tel;
        insertQuery.bindValue(":telContact", QString::fromStdString(tel));

        //meme choses pour les dates
        year_month_day dateCrea = contact->getDateCreaContact();
        stringstream streamDateCrea;
        string chaineDateCrea;
        streamDateCrea << dateCrea;
        streamDateCrea >> chaineDateCrea;
        insertQuery.bindValue(":dateCreaContact", QString::fromStdString(chaineDateCrea));

        year_month_day dateDernModif = contact->getDateDernModif();
        stringstream streamDateDernModif;
        string chaineDateDernModif;
        streamDateDernModif << dateDernModif;
        streamDateDernModif >> chaineDateDernModif;
        insertQuery.bindValue(":dateDernModifContact", QString::fromStdString(chaineDateDernModif));


        if(!insertQuery.exec()){
            cerr << "Erreur lors de l'insertion dans la BDD" << insertQuery.lastError().text().toStdString() << endl;
            return false;
        }
        else{
            //apres avoir inserer un nouveau contact on remet a jour la liste des contacts
            hydrateContactList();
            cout << "Contact insere avec succes" << endl;
            return true;
        }

    } catch (const exception & e) {
        cerr <<"Erreur lors de la preparation de la requete insert contact" << e.what() << endl;
        return false;
    }


}

bool GestionnaireBDD::updateContact(ContactEntity *contact, ContactEntity *contactEntityModifie)
{
    try {
        QSqlQuery updateQuery(db);
        updateQuery.prepare("UPDATE contact SET nomContact = :nomContact, prenomContact = :prenomContact, entrepriseContact = :entrepriseContact, uriPhotoContact = :uriPhotoContact, mailContact = :mailContact, telContact = :telContact, dateDernModifContact = :dateDernModifContact WHERE idContact = :idContact");

        //on recupere chacune des valeurs string depuis l'objet contatEntityModifie en parametre pour les binds
        updateQuery.bindValue(":idContact", contact->getIdContact());
        updateQuery.bindValue(":nomContact", QString::fromStdString(contactEntityModifie->getNomContact()));
        updateQuery.bindValue(":prenomContact", QString::fromStdString(contactEntityModifie->getPrenomContact()));
        updateQuery.bindValue(":entrepriseContact", QString::fromStdString(contactEntityModifie->getEntrepriseContact()));
        updateQuery.bindValue(":uriPhotoContact", QString::fromStdString(contactEntityModifie->getPhotoContact()));
        updateQuery.bindValue(":mailContact", QString::fromStdString(contactEntityModifie->getMailContact()));

        //pour le numero de telephone il faut envoyer chacun des chiffres dans un stream qu'on convertit ensuite en string
        list<unsigned> listeNumeros = contactEntityModifie->getTelContact();
        stringstream streamChiffres;
        string tel;
        for (unsigned &chiffre : listeNumeros){
            streamChiffres << chiffre;
        }
        streamChiffres >> tel;
        updateQuery.bindValue(":telContact", QString::fromStdString(tel));

        year_month_day dateDernModif = contactEntityModifie->getDateDernModif();
        stringstream streamDateDernModif;
        string chaineDateDernModif;
        streamDateDernModif << dateDernModif;
        streamDateDernModif >> chaineDateDernModif;
        updateQuery.bindValue(":dateDernModifContact", QString::fromStdString(chaineDateDernModif));

        if(!updateQuery.exec()){
            cerr << "Erreur lors de l'update du contact dans la BDD" << updateQuery.lastError().text().toStdString()<< endl;
            return false;
        }
        else{
            cout << "Contact modifie en base" << updateQuery.lastError().text().toStdString()<< endl;
            return true;
        }

    } catch (const exception & e) {
        cerr <<"Erreur lors de la preparation de la requete update contact" << e.what() << endl;
        return false;
    }

}

bool GestionnaireBDD::deleteContact(ContactEntity *contact)
{
    try {
        QSqlQuery deleteQuery(db);
        deleteQuery.prepare("Delete from Contact where idContact = :idContact");

        deleteQuery.bindValue(":idContact",contact->getIdContact());

        if(!deleteQuery.exec()){
            cerr << "Erreur lors du delete en base" << deleteQuery.lastError().text().toStdString() << endl;
            return false;
        }
        else{
            cout << "Contact supprime en base" << endl;
            return true;
        }
    } catch (const exception & e) {
        cerr <<"Erreur lors de la preparation de la requete delete contact" << e.what() << endl;
        return false;
    }


}

bool GestionnaireBDD::hydrateInteractionList()
{
    listInteractionEntity.clear();
    QSqlQuery query(db);

    //si query.exec renvoie false cela signifie qu'il y a eu une erreur au moment de l'execution de la requete
    if(!query.exec("SELECT idInteraction, contenuInteraction, dateAjoutInteraction FROM Interaction")){
        cerr << "Erreur lors de la selection des interactions dans la BDD "<<query.lastError().text().toStdString() << endl;
        return false;
    }else{
        try {
            while(query.next()){

                //cette partie du code separe la chaine de caractere donne la date d'e creation'ajout en trois parties et la stocke dans un vector
                std::vector<std::string> partiesDate;
                std::string partie;
                std::istringstream dateStream(query.value(2).toString().toStdString());
                while (std::getline(dateStream, partie, '-'))
                {
                   partiesDate.push_back(partie);
                }

                //convertit chacune des trois parties de la date en entier
                int annee = std::stoi(partiesDate.at(0));
                int mois = std::stoi(partiesDate.at(1));
                int jour = std::stoi(partiesDate.at(2));

                //pour creer la date approprie
                year_month_day dateAjout =year{annee}/mois/jour;

                int id = query.value(0).toInt();
                string contenu = query.value(1).toString().toStdString();

                InteractionEntity * interaction = new InteractionEntity(id,contenu,dateAjout);

                listInteractionEntity.push_back(interaction);
            }

            cout << "Liste des interactions mis a jour avec succes" << endl;
            return true;

        } catch (const exception & e) {
            cerr <<"Erreur lors du remplissage de la liste interaction" << e.what() << endl;
            return false;
        }

    }
}

bool GestionnaireBDD::insertInteraction(InteractionEntity *interaction)
{
    try {
        QSqlQuery insertQuery(db);
        insertQuery.prepare("INSERT INTO Interaction (contenuInteraction, dateAjoutInteraction) "
                      "VALUES (:contenuInteraction, :dateAjoutInteraction)");

        //on recupere chacune des valeurs string depuis l'objet en parametre pour les binds
        insertQuery.bindValue(":contenuInteraction", QString::fromStdString(interaction->getContenuInteraction()));

        //meme choses pour les dates
        year_month_day dateAjout = interaction->getDateAjoutInteraction();
        stringstream streamDateAjout;
        string chaineDateAjout;
        streamDateAjout << dateAjout;
        streamDateAjout >> chaineDateAjout;
        insertQuery.bindValue(":dateAjoutInteraction", QString::fromStdString(chaineDateAjout));


        if(!insertQuery.exec()){
            cerr << "Erreur lors de l'insertion de l'interaction dans la BDD" << insertQuery.lastError().text().toStdString() << endl;
            return false;
        }
        else{
            //apres avoir inserer un nouveau contact on remet a jour la liste des contacts
            hydrateInteractionList();
            cout << "Interaction insere avec succes" << endl;
            return true;
        }

    } catch (const exception & e) {
        cerr <<"Erreur lors de la preparation de la requete insert interaction" << e.what() << endl;
        return false;
    }
}

bool GestionnaireBDD::updateInteraction(InteractionEntity *interaction, InteractionEntity *interactionModifie)
{
    try {
        QSqlQuery updateQuery(db);
        updateQuery.prepare("UPDATE interaction SET contenuInteraction = :contenuInteraction WHERE idInteraction = :idInteraction");

        //on recupere chacune des valeurs string depuis l'objet interactionModifie en parametre pour les binds
        updateQuery.bindValue(":idInteraction", interaction->getIdInteraction());
        updateQuery.bindValue(":contenuInteraction", QString::fromStdString(interactionModifie->getContenuInteraction()));

        if(!updateQuery.exec()){
            cerr << "Erreur lors de l'update de l'interaction dans la BDD" << updateQuery.lastError().text().toStdString()<< endl;
            return false;
        }
        else{
            cout << "Interaction modifie en base" << endl;
            return true;
        }

    } catch (const exception & e) {
        cerr <<"Erreur lors de la preparation de la requete update contact" << e.what() << endl;
        return false;
    }
}

bool GestionnaireBDD::deleteInteraction(InteractionEntity *interaction)
{
    try {
        QSqlQuery deleteQuery(db);
        deleteQuery.prepare("Delete from Interaction where idInteraction = :idInteraction");

        deleteQuery.bindValue(":idInteraction",interaction->getIdInteraction());

        if(!deleteQuery.exec()){
            cerr << "Erreur lors du delete d'interaction en base" << deleteQuery.lastError().text().toStdString() << endl;
            return false;
        }
        else{
            cout << "Interaction supprimee en base" << endl;
            return true;
        }
    } catch (const exception & e) {
        cerr <<"Erreur lors de la preparation de la requete delete interaction" << e.what() << endl;
        return false;
    }
}

bool GestionnaireBDD::hydrateContactInteractionList()
{
    listContactInteractionEntity.clear();
    QSqlQuery query(db);

    //si query.exec renvoie false cela signifie qu'il y a eu une erreur au moment de l'execution de la requete
    if(!query.exec("SELECT idContactInteraction, idContact, idInteraction FROM ContactInteraction")){
        cerr << "Erreur lors de la selection des ContactInteraction dans la BDD "<<query.lastError().text().toStdString() << endl;
        return false;
    }else{
        try {
            while(query.next()){

                int idContactInteraction = query.value(0).toInt();
                int idContact = query.value(1).toInt();
                int idInteraction = query.value(2).toInt();

                auto itContact = std::find_if(listContactEntity.begin(),listContactEntity.end(), [idContact](ContactEntity *contact){return  contact->getIdContact()==idContact;});

                auto itInteraction = std::find_if(listInteractionEntity.begin(),listInteractionEntity.end(), [idInteraction](InteractionEntity *interaction){return  interaction->getIdInteraction()==idInteraction;});

                ContactEntity * contact= *itContact;

                InteractionEntity * interaction = *itInteraction;

                ContactInteractionEntity * contactInteraction = new ContactInteractionEntity(idContactInteraction, contact, interaction);

                listContactInteractionEntity.push_back(contactInteraction);
            }

            cout << "Liste des contactinteraction mis a jour avec succes" << endl;
            return true;

        } catch (const exception & e) {
            cerr <<"Erreur lors du remplissage de la liste contactinteraction" << e.what() << endl;
            return false;
        }

    }
}

bool GestionnaireBDD::insertContactInteraction(ContactInteractionEntity *contactInteraction)
{
    try {
        QSqlQuery insertQuery(db);
        insertQuery.prepare("INSERT INTO ContactInteraction (idContact, idInteraction) "
                      "VALUES (:idContact, :idInteraction)");

        //on recupere chacune des valeurs string depuis l'objet en parametre pour les binds
        insertQuery.bindValue(":idContact", contactInteraction->getIdContactEntity());
        insertQuery.bindValue(":idInteraction", contactInteraction->getIdInteractionEntity());

        if(!insertQuery.exec()){
            cerr << "Erreur lors de l'insertion de la ContactInteraction dans la BDD" << insertQuery.lastError().text().toStdString() << endl;
            return false;
        }
        else{
            //apres avoir inserer un nouveau contact on remet a jour la liste des contacts
            hydrateContactInteractionList();
            cout << "ContactInteraction insere avec succes" << endl;
            return true;
        }

    } catch (const exception & e) {
        cerr <<"Erreur lors de la preparation de la requete insert ContactInteraction" << e.what() << endl;
        return false;
    }
}

bool GestionnaireBDD::hydrateTodoList()
{
    listTodoEntity.clear();
    QSqlQuery query(db);

    //si query.exec renvoie false cela signifie qu'il y a eu une erreur au moment de l'execution de la requete
    if(!query.exec("SELECT idTodo, contenuTodo, dateAjoutTodo FROM Todo")){
        cerr << "Erreur lors de la selection des todos dans la BDD "<<query.lastError().text().toStdString() << endl;
        return false;
    }else{
        try {
            while(query.next()){

                //cette partie du code separe la chaine de caractere donne la date d'e creation'ajout en trois parties et la stocke dans un vector
                std::vector<std::string> partiesDate;
                std::string partie;
                std::istringstream dateStream(query.value(2).toString().toStdString());
                while (std::getline(dateStream, partie, '-'))
                {
                   partiesDate.push_back(partie);
                }

                //convertit chacune des trois parties de la date en entier
                int annee = std::stoi(partiesDate.at(0));
                int mois = std::stoi(partiesDate.at(1));
                int jour = std::stoi(partiesDate.at(2));

                //pour creer la date approprie
                year_month_day dateAjout =year{annee}/mois/jour;

                int id = query.value(0).toInt();
                string contenu = query.value(1).toString().toStdString();

                TodoEntity * todo = new TodoEntity(id,contenu,dateAjout);

                listTodoEntity.push_back(todo);
            }

            cout << "Liste des todos mise a jour avec succes" << endl;
            return true;

        } catch (const exception & e) {
            cerr <<"Erreur lors du remplissage de la liste des todos" << e.what() << endl;
            return false;
        }

    }
}

bool GestionnaireBDD::insertTodo(TodoEntity *todo)
{
    try {
        QSqlQuery insertQuery(db);
        insertQuery.prepare("INSERT INTO Todo (contenuTodo, dateAjoutTodo) "
                      "VALUES (:contenuTodo, :dateAjoutTodo)");

        //on recupere chacune des valeurs string depuis l'objet en parametre pour les binds
        insertQuery.bindValue(":contenuTodo", QString::fromStdString(todo->getContenuTodo()));

        //meme choses pour les dates
        year_month_day dateAjout = todo->getDateAjoutTodo();
        stringstream streamDateAjout;
        string chaineDateAjout;
        streamDateAjout << dateAjout;
        streamDateAjout >> chaineDateAjout;
        insertQuery.bindValue(":dateAjoutTodo", QString::fromStdString(chaineDateAjout));


        if(!insertQuery.exec()){
            cerr << "Erreur lors de l'insertion du todo dans la BDD" << insertQuery.lastError().text().toStdString() << endl;
            return false;
        }
        else{
            //apres avoir inserer un nouveau contact on remet a jour la liste des contacts
            hydrateTodoList();
            cout << "Todo insere avec succes" << endl;
            return true;
        }

    } catch (const exception & e) {
        cerr <<"Erreur lors de la preparation de la requete insert interaction" << e.what() << endl;
        return false;
    }
}

bool GestionnaireBDD::updateTodo(TodoEntity *todo, TodoEntity *todoModifie)
{
    try {
        QSqlQuery updateQuery(db);
        updateQuery.prepare("UPDATE todo SET contenuTodo = :contenuTodo WHERE idTodo = :idTodo");

        //on recupere chacune des valeurs string depuis l'objet interactionModifie en parametre pour les binds
        updateQuery.bindValue(":idTodo", todo->getIdTodo());
        updateQuery.bindValue(":contenuTodo", QString::fromStdString(todoModifie->getContenuTodo()));

        if(!updateQuery.exec()){
            cerr << "Erreur lors de l'update du todo dans la BDD" << updateQuery.lastError().text().toStdString()<< endl;
            return false;
        }
        else{
            cout << "Todo modifie en base" << endl;
            return true;
        }

    } catch (const exception & e) {
        cerr <<"Erreur lors de la preparation de la requete update todo" << e.what() << endl;
        return false;
    }
}

bool GestionnaireBDD::deleteTodo(TodoEntity *todo)
{
    try {
        QSqlQuery deleteQuery(db);
        deleteQuery.prepare("Delete from Todo where idTodo = :idTodo");

        deleteQuery.bindValue(":idTodo",todo->getIdTodo());

        if(!deleteQuery.exec()){
            cerr << "Erreur lors du delete du todo en base" << deleteQuery.lastError().text().toStdString() << endl;
            return false;
        }
        else{
            cout << "Todo supprimee en base" << endl;
            return true;
        }
    } catch (const exception & e) {
        cerr <<"Erreur lors de la preparation de la requete delete todo" << e.what() << endl;
        return false;
    }
}

bool GestionnaireBDD::hydrateInteractionTodoList()
{
    listInteractionTodoEntity.clear();
    QSqlQuery query(db);

    //si query.exec renvoie false cela signifie qu'il y a eu une erreur au moment de l'execution de la requete
    if(!query.exec("SELECT idInteractionTodo, idInteraction, idTodo FROM InteractionTodo")){
        cerr << "Erreur lors de la selection des InteractionTodo dans la BDD "<<query.lastError().text().toStdString() << endl;
        return false;
    }else{
        try {
            while(query.next()){

                int idInteractionTodo = query.value(0).toInt();
                int idInteraction = query.value(1).toInt();
                int idTodo = query.value(2).toInt();

                auto itInteraction = std::find_if(listInteractionEntity.begin(),listInteractionEntity.end(), [idInteraction](InteractionEntity *interaction){return  interaction->getIdInteraction()==idInteraction;});

                auto itTodo = std::find_if(listTodoEntity.begin(),listTodoEntity.end(), [idTodo](TodoEntity *todo){return  todo->getIdTodo()==idTodo;});

                InteractionEntity * interaction = *itInteraction;

                TodoEntity * todo = *itTodo;

                InteractionTodoEntity * interactionTodoEntity = new InteractionTodoEntity(idInteractionTodo, interaction, todo);

                listInteractionTodoEntity.push_back(interactionTodoEntity);
            }

            cout << "Liste des interactiontodo mis a jour avec succes" << endl;
            return true;

        } catch (const exception & e) {
            cerr <<"Erreur lors du remplissage de la liste interactiontodo" << e.what() << endl;
            return false;
        }

    }
}

bool GestionnaireBDD::insertInteractionTodo(InteractionTodoEntity *interactionTodo)
{
    try {
        QSqlQuery insertQuery(db);
        insertQuery.prepare("INSERT INTO InteractionTodo (idInteraction, idTodo) "
                      "VALUES (:idInteraction, :idTodo)");

        //on recupere chacune des valeurs string depuis l'objet en parametre pour les binds
        insertQuery.bindValue(":idInteraction", interactionTodo->getIdInteraction());
        insertQuery.bindValue(":idTodo", interactionTodo->getIdTodo());

        if(!insertQuery.exec()){
            cerr << "Erreur lors de l'insertion de l'interactiontodo dans la BDD" << insertQuery.lastError().text().toStdString() << endl;
            return false;
        }
        else{
            //apres avoir inserer un nouveau contact on remet a jour la liste des contacts
            hydrateInteractionTodoList();
            cout << "interactiontodo insere avec succes" << endl;
            return true;
        }

    } catch (const exception & e) {
        cerr <<"Erreur lors de la preparation de la requete insert interactiontodo" << e.what() << endl;
        return false;
    }
}
