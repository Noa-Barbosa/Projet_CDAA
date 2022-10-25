#include "gestionnairelistes.h"

GestionnaireListes::GestionnaireListes()
{

}

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

void GestionnaireListes::addInteraction(InteractionEntity interaction, ContactEntity contact)
{
    //si l'interaction n'existe pas deja dans la liste
    if(!isInteractionInList(interaction)){
        listInteractionEntity.push_back(interaction);

        ContactInteractionEntity contactInteraction(contact, interaction);

        listContactInteractionEntity.push_back(contactInteraction);
    }
    else{
        cout << "L'interaction existe deja dans la liste elle n'a pas ete ajoute" << std::endl;
    }
}

void GestionnaireListes::editInteraction(InteractionEntity interaction, InteractionEntity interactionModif)
{
    if(isInteractionInList(interaction)){

        //Ici il faut recuperer la liste de tout les contacts et les todos des entites associations qui ont cette interaction
        //ensuite les supprimer
        //puis creer des nouvelles entites associations avec la listes des contacts et todos
        //et les ajouter a leur liste respective
        listInteractionEntity.remove(interaction);
    }
    else{
        cout << "L'interaction n'existe pas rien n'a ete fait" << std::endl;
    }

}

void GestionnaireListes::deleteInteraction(InteractionEntity interaction)
{
    //il faut supprimer l'interaction de la liste si elle existe bien
    //et faire de même pour toute ces entites associations
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
