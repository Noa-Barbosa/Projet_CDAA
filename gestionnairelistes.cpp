#include "gestionnairelistes.h"

GestionnaireListes::GestionnaireListes(const QString& path)
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
}

const list<ContactEntity *> &GestionnaireListes::getListContactEntity() const
{
    return listContactEntity;
}

void GestionnaireListes::setListContactEntity(const list<ContactEntity *> &newListContactEntity)
{
    listContactEntity = newListContactEntity;
}

const list<InteractionEntity *> &GestionnaireListes::getListInteractionEntity() const
{
    return listInteractionEntity;
}

void GestionnaireListes::setListInteractionEntity(const list<InteractionEntity *> &newListInteractionEntity)
{
    listInteractionEntity = newListInteractionEntity;
}

const list<TodoEntity *> &GestionnaireListes::getListTodoEntity() const
{
    return listTodoEntity;
}

void GestionnaireListes::setListTodoEntity(const list<TodoEntity *> &newListTodoEntity)
{
    listTodoEntity = newListTodoEntity;
}

const list<ContactInteractionEntity *> &GestionnaireListes::getListContactInteractionEntity() const
{
    return listContactInteractionEntity;
}

void GestionnaireListes::setListContactInteractionEntity(const list<ContactInteractionEntity *> &newListContactInteractionEntity)
{
    listContactInteractionEntity = newListContactInteractionEntity;
}

const list<InteractionTodoEntity *> &GestionnaireListes::getListInteractionTodoEntity() const
{
    return listInteractionTodoEntity;
}

void GestionnaireListes::setListInteractionTodoEntity(const list<InteractionTodoEntity *> &newListInteractionTodoEntity)
{
    listInteractionTodoEntity = newListInteractionTodoEntity;
}

bool GestionnaireListes::isContactInList(ContactEntity *contactRecherche)
{
    list<ContactEntity*>::iterator findIter = find(listContactEntity.begin(), listContactEntity.end(), contactRecherche);

    if(findIter!=listContactEntity.end()){
        return true;
    }
    else{
        return false;
    }

}


bool GestionnaireListes::isInteractionInList(InteractionEntity *interactionRecherche)
{
    list<InteractionEntity*>::iterator findIter = find(listInteractionEntity.begin(), listInteractionEntity.end(), interactionRecherche);

    if(findIter!=listInteractionEntity.end()){
        return true;
    }
    else{
        return false;
    }

}

bool GestionnaireListes::isTodoInList(TodoEntity *todoRecherche)
{
    list<TodoEntity*>::iterator findIter = find(listTodoEntity.begin(), listTodoEntity.end(), todoRecherche);

    if(findIter!=listTodoEntity.end()){
        return true;
    }
    else{
        return false;
    }
}

bool GestionnaireListes::isContactInteractionInList(ContactInteractionEntity *contactInteractionRecherche)
{
    list<ContactInteractionEntity*>::iterator findIter = find(listContactInteractionEntity.begin(), listContactInteractionEntity.end(), contactInteractionRecherche);

    if(findIter!=listContactInteractionEntity.end()){
        return true;
    }
    else{
        return false;
    }
}

bool GestionnaireListes::isInteractionTodoInList(InteractionTodoEntity *interactionTodoRecherche)
{
    list<InteractionTodoEntity*>::iterator findIter = find(listInteractionTodoEntity.begin(), listInteractionTodoEntity.end(), interactionTodoRecherche);

    if(findIter!=listInteractionTodoEntity.end()){
        return true;
    }
    else{
        return false;
    }
}
