#include "gestionnaireinteraction.h"

GestionnaireInteraction::GestionnaireInteraction()
{

}

void GestionnaireInteraction::addInteraction(InteractionEntity interaction, ContactEntity contact)
{
    //a chaque fois qu'on veut faire une operation sur une liste on recupere la liste actuelle avec le gestionnaire de liste (plus tard se sera un appel sur la base)
    auto listInteractionEntity = GestionnaireListes::getInstance().getListInteractionEntity();
    auto listContactInteractionEntity = GestionnaireListes::getInstance().getListContactInteractionEntity();

    //si l'interaction n'existe pas deja dans la liste
    if(!GestionnaireListes::getInstance().isInteractionInList(interaction)){

        listInteractionEntity.push_back(interaction);

        ContactInteractionEntity contactInteraction(contact, interaction);

        listContactInteractionEntity.push_back(contactInteraction);

        GestionnaireListes::getInstance().setListInteractionEntity(listInteractionEntity);
        GestionnaireListes::getInstance().setListContactInteractionEntity(listContactInteractionEntity);

    }
    else{
        cout << "L'interaction existe deja dans la liste elle n'a pas ete ajoute" << std::endl;
    }
}


void GestionnaireInteraction::editInteraction(InteractionEntity interaction, InteractionEntity interactionModif)
{

    if(GestionnaireListes::getInstance().isInteractionInList(interaction)){

        auto listInteractionEntity = GestionnaireListes::getInstance().getListInteractionEntity();
        auto listContactInteractionEntity = GestionnaireListes::getInstance().getListContactInteractionEntity();
        auto listInteractionTodoEntity = GestionnaireListes::getInstance().getListInteractionTodoEntity();

        list<ContactInteractionEntity> contactInteractionAsupprimer;

        //on recupere tout les contacts interaction associe avec l'interaction modifie
        for(ContactInteractionEntity& contactInteraction : listContactInteractionEntity)
        {
           if(contactInteraction.getInteractionEntity()==interaction){
               //on les mets dans la liste des contactinteraction a supprimer
               contactInteractionAsupprimer.push_back(contactInteraction);
           }
        }

        //puis pour chaque contactinteraction a supprimer on supprime le contactinteraction de la liste
        //puis on creer un nouveau contactinteraction avec l'interaction modifie
        //puis on l'ajoute a la liste
        for(ContactInteractionEntity& contactInteractionAsupprimer : contactInteractionAsupprimer)
        {
           listContactInteractionEntity.remove(contactInteractionAsupprimer);
           ContactInteractionEntity nvContactInteractionEntity(contactInteractionAsupprimer.getContactEntity(),interactionModif);
           listContactInteractionEntity.push_back(nvContactInteractionEntity);
        }

        list<InteractionTodoEntity> interactionTodoAsupprimer;

        for(InteractionTodoEntity& interactionTodo : listInteractionTodoEntity)
        {
           if(interactionTodo.getInteractionEntity()==interaction){
               interactionTodoAsupprimer.push_back(interactionTodo);
           }
        }

        for(InteractionTodoEntity& interactionTodoAsupprimer : interactionTodoAsupprimer)
        {
           listInteractionTodoEntity.remove(interactionTodoAsupprimer);
           InteractionTodoEntity nvInteractionTodoEntity(interactionModif,interactionTodoAsupprimer.getTodoEntity());
           listInteractionTodoEntity.push_back(nvInteractionTodoEntity);
        }

        listInteractionEntity.remove(interaction);
        listInteractionEntity.push_back(interactionModif);

        GestionnaireListes::getInstance().setListInteractionEntity(listInteractionEntity);
        GestionnaireListes::getInstance().setListContactInteractionEntity(listContactInteractionEntity);
        GestionnaireListes::getInstance().setListInteractionTodoEntity(listInteractionTodoEntity);

    }
    else{
        cout << "L'interaction n'existe pas rien n'a ete fait" << std::endl;
    }


}

void GestionnaireInteraction::deleteInteraction(InteractionEntity interaction)
{
    if(GestionnaireListes::getInstance().isInteractionInList(interaction)){

        auto listInteractionEntity = GestionnaireListes::getInstance().getListInteractionEntity();
        auto listContactInteractionEntity = GestionnaireListes::getInstance().getListContactInteractionEntity();
        auto listInteractionTodoEntity = GestionnaireListes::getInstance().getListInteractionTodoEntity();

        list<ContactInteractionEntity> contactInteractionAsupprimer;

        //on recupere tout les contacts interaction associe avec l'interaction modifie
        for(ContactInteractionEntity& contactInteraction : listContactInteractionEntity)
        {
           if(contactInteraction.getInteractionEntity()==interaction){
               //on les mets dans la liste des contactinteraction a supprimer
               contactInteractionAsupprimer.push_back(contactInteraction);
           }
        }

        //puis pour chaque contactinteraction a supprimer on supprime le contactinteraction de la liste
        for(ContactInteractionEntity& contactInteractionAsupprimer : contactInteractionAsupprimer)
        {
           listContactInteractionEntity.remove(contactInteractionAsupprimer);
        }

        list<InteractionTodoEntity> interactionTodoAsupprimer;

        for(InteractionTodoEntity& interactionTodo : listInteractionTodoEntity)
        {
           if(interactionTodo.getInteractionEntity()==interaction){
               interactionTodoAsupprimer.push_back(interactionTodo);
           }
        }

        for(InteractionTodoEntity& interactionTodoAsupprimer : interactionTodoAsupprimer)
        {
           listInteractionTodoEntity.remove(interactionTodoAsupprimer);
        }

        listInteractionEntity.remove(interaction);

        GestionnaireListes::getInstance().setListInteractionEntity(listInteractionEntity);
        GestionnaireListes::getInstance().setListContactInteractionEntity(listContactInteractionEntity);
        GestionnaireListes::getInstance().setListInteractionTodoEntity(listInteractionTodoEntity);

    }
    else{
        cout << "L'interaction n'existe pas rien n'a ete fait" << std::endl;
    }

}
