#include "gestionnaireinteraction.h"

GestionnaireInteraction::GestionnaireInteraction()
{

}

void GestionnaireInteraction::addInteraction(InteractionEntity interaction, ContactEntity contact)
{
    //a chaque fois qu'on veut faire une operation sur une liste on recupere la liste actuelle avec le gestionnaire de liste
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
    /**
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
    */

}

void GestionnaireInteraction::deleteInteraction(InteractionEntity interaction)
{
    //il faut supprimer l'interaction de la liste si elle existe bien
    //et faire de même pour toute ces entites associations
}
