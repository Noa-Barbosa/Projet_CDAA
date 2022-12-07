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
    QSqlQuery query(db);
    query.exec("SELECT idContact, nomContact, prenomContact, entrepriseContact, uriPhotoContact, mailContact, telContact, dateCreaContact, dateDernModifContact FROM Contact");

    while(query.next()){
        list<unsigned>  tel;
        for (auto &chiffre : query.value(6).toString().toStdString()) {
                tel.push_back((unsigned) chiffre - '0');
            }

        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(query.value(7).toString().toStdString());
        while (std::getline(tokenStream, token, '-'))
        {
           tokens.push_back(token);
        }

        int annee = std::stoi(tokens.at(0));
        int mois = std::stoi(tokens.at(1));
        int jour = std::stoi(tokens.at(2));

        auto dateCrea =year{annee}/mois/jour;

        tokens.clear();
        std::istringstream tokenStream2(query.value(7).toString().toStdString());
        while (std::getline(tokenStream2, token, '-'))
        {
           tokens.push_back(token);
        }

        annee = std::stoi(tokens.at(0));
        mois = std::stoi(tokens.at(1));
        jour = std::stoi(tokens.at(2));

        auto dateDernModif =year{annee}/mois/jour;

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
