#include "gestionnairelistes.h"

const list<ContactEntity> &GestionnaireListes::getListContactEntity() const
{
    return listContactEntity;
}

const list<InteractionEntity> &GestionnaireListes::getListInteractionEntity() const
{
    return listInteractionEntity;
}

const list<TodoEntity> &GestionnaireListes::getListTodoEntity() const
{
    return listTodoEntity;
}

const list<ContactInteractionEntity> &GestionnaireListes::getListContactInteractionEntity() const
{
    return listContactInteractionEntity;
}

const list<InteractionTodoEntity> &GestionnaireListes::getListInteractionTodoEntity() const
{
    return listInteractionTodoEntity;
}

void GestionnaireListes::setListContactEntity(const list<ContactEntity> &newListContactEntity)
{
    listContactEntity = newListContactEntity;
}

void GestionnaireListes::setListInteractionEntity(const list<InteractionEntity> &newListInteractionEntity)
{
    listInteractionEntity = newListInteractionEntity;
}

void GestionnaireListes::setListTodoEntity(const list<TodoEntity> &newListTodoEntity)
{
    listTodoEntity = newListTodoEntity;
}

void GestionnaireListes::setListContactInteractionEntity(const list<ContactInteractionEntity> &newListContactInteractionEntity)
{
    listContactInteractionEntity = newListContactInteractionEntity;
}

void GestionnaireListes::setListInteractionTodoEntity(const list<InteractionTodoEntity> &newListInteractionTodoEntity)
{
    listInteractionTodoEntity = newListInteractionTodoEntity;
}

bool GestionnaireListes::isInteractionInList(InteractionEntity interactionRecherche)
{
    list<InteractionEntity>::iterator findIter = find(listInteractionEntity.begin(), listInteractionEntity.end(), interactionRecherche);

    if(findIter!=listInteractionEntity.end()){
        return true;
    }
    else{
        return false;
    }

}
