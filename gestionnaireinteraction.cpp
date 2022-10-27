#include "gestionnaireinteraction.h"

GestionnaireInteraction::GestionnaireInteraction(GestionnaireListes *gestionnaire)
{
    gestionnaireListes=gestionnaire;
}

void GestionnaireInteraction::addInteraction(InteractionEntity *interaction, ContactEntity *contact)
{
    //a chaque fois qu'on veut faire une operation sur une liste on recupere la liste actuelle avec le gestionnaire de liste (plus tard se sera un appel sur la base)
    auto listInteractionEntity = gestionnaireListes->getListInteractionEntity();
    auto listContactInteractionEntity = gestionnaireListes->getListContactInteractionEntity();

    //si l'interaction n'existe pas deja dans la liste
    if(!gestionnaireListes->isInteractionInList(interaction)){
        listInteractionEntity.push_back(interaction);
        gestionnaireListes->setListInteractionEntity(listInteractionEntity);
    }
    else{
        cout << "L'interaction existe deja dans la liste elle n'a pas ete ajoute" << std::endl<<std::endl;
    }

    ContactInteractionEntity *contactInteraction = new ContactInteractionEntity(contact, interaction);
    if(!gestionnaireListes->isContactInteractionInList(contactInteraction)){
        listContactInteractionEntity.push_back(contactInteraction);
        gestionnaireListes->setListContactInteractionEntity(listContactInteractionEntity);
    }
    else{
        cout << "Le contact a deja cette interaction les deux n'ont pas ete lie" << std::endl<<std::endl;
    }

}


void GestionnaireInteraction::editInteraction(InteractionEntity* interaction, InteractionEntity* interactionModif)
{

    interaction->setContenuInteraction(interactionModif->getContenuInteraction());

}

void GestionnaireInteraction::deleteInteraction(InteractionEntity* interaction)
{

    if(gestionnaireListes->isInteractionInList(interaction)){

        auto listInteractionEntity = gestionnaireListes->getListInteractionEntity();
        auto listContactInteractionEntity = gestionnaireListes->getListContactInteractionEntity();
        auto listInteractionTodoEntity = gestionnaireListes->getListInteractionTodoEntity();
        auto listTodoEntity = gestionnaireListes->getListTodoEntity();

        list<ContactInteractionEntity*> contactInteractionAsupprimer;
        list<TodoEntity*> todoASupprimer;

        //on recupere tout les contacts interaction associe avec l'interaction modifie
        for(ContactInteractionEntity* contactInteraction : listContactInteractionEntity)
        {
           if(contactInteraction->getInteractionEntity()==interaction){
               //on les mets dans la liste des contactinteraction a supprimer
               contactInteractionAsupprimer.push_back(contactInteraction);
           }
        }

        //puis pour chaque contactinteraction a supprimer on supprime le contactinteraction de la liste
        for(ContactInteractionEntity* contactInteractionAsupprimer : contactInteractionAsupprimer)
        {
           listContactInteractionEntity.remove(contactInteractionAsupprimer);
        }

        list<InteractionTodoEntity*> interactionTodoAsupprimer;

        for(InteractionTodoEntity* interactionTodo : listInteractionTodoEntity)
        {
           if(interactionTodo->getInteractionEntity()==interaction){
               interactionTodoAsupprimer.push_back(interactionTodo);
               todoASupprimer.push_back(interactionTodo->getTodoEntity());
           }
        }

        for(InteractionTodoEntity* interactionTodoAsupprimer : interactionTodoAsupprimer)
        {
           listInteractionTodoEntity.remove(interactionTodoAsupprimer);
        }

        for(TodoEntity* todoASupprimer : todoASupprimer)
        {
            listTodoEntity.remove(todoASupprimer);
        }

        listInteractionEntity.remove(interaction);

        gestionnaireListes->setListInteractionEntity(listInteractionEntity);
        gestionnaireListes->setListContactInteractionEntity(listContactInteractionEntity);
        gestionnaireListes->setListInteractionTodoEntity(listInteractionTodoEntity);
        gestionnaireListes->setListTodoEntity(listTodoEntity);

    }
    else{
        cout << "L'interaction n'existe pas rien n'a ete fait" << std::endl<<std::endl;
    }



}
