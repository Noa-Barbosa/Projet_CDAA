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
    }

    updateContactList();
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

void GestionnaireBDD::updateContactList()
{
    listContactEntity.clear();
    QSqlQuery query(db);
    query.exec("SELECT idContact, nomContact, prenomContact, entrepriseContact, uriPhotoContact, mailContact, telContact, dateCreaContact, dateDernModifContact FROM Contact");

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
}

void GestionnaireBDD::insertContact(ContactEntity *contact)
{
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
        qDebug() << "Erreur lors de l'insertion dans la BDD" << insertQuery.lastError().text();
    }

    updateContactList();

}

void GestionnaireBDD::updateContact(ContactEntity *contact, ContactEntity *contactEntityModifie)
{
    QSqlQuery updateQuery(db);
    updateQuery.prepare("UPDATE contact SET nomContact = :nomContact, prenomContact = :prenomContact, entrepriseContact = :entrepriseContact, uriPhotoContact = :uriPhotoContact, mailContact = :mailContact, telContact = :telContact, dateCreaContact = :dateCreaContact, dateDernModifContact = :dateDernModifContact WHERE idContact = :idContact");

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

    //meme choses pour les dates
    year_month_day dateCrea = contactEntityModifie->getDateCreaContact();
    stringstream streamDateCrea;
    string chaineDateCrea;
    streamDateCrea << dateCrea;
    streamDateCrea >> chaineDateCrea;
    updateQuery.bindValue(":dateCreaContact", QString::fromStdString(chaineDateCrea));

    year_month_day dateDernModif = contactEntityModifie->getDateDernModif();
    stringstream streamDateDernModif;
    string chaineDateDernModif;
    streamDateDernModif << dateDernModif;
    streamDateDernModif >> chaineDateDernModif;
    updateQuery.bindValue(":dateDernModifContact", QString::fromStdString(chaineDateDernModif));

    if(!updateQuery.exec()){
        qDebug() << "Erreur lors de l'update dans la BDD" << updateQuery.lastError().text();
    }
    else{
        qDebug() << "Contact modifie en base" << updateQuery.lastError().text();

        //a changer
        contact->setNomContact(contactEntityModifie->getNomContact());
        contact->setPrenomContact(contactEntityModifie->getPrenomContact());
        contact->setEntrepriseContact(contactEntityModifie->getEntrepriseContact());
        contact->setTelContact(contactEntityModifie->getTelContact());
        contact->setMailContact(contactEntityModifie->getMailContact());
        contact->setPhotoContact(contactEntityModifie->getPhotoContact());
        contact->setDateDernModif(year_month_day{floor<days>(system_clock::now())});
    }



}
