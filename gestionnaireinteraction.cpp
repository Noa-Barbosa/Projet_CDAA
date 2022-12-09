#include "gestionnaireinteraction.h"

GestionnaireInteraction::GestionnaireInteraction(GestionnaireBDD *gestionnaire)
{
    gestionnaireBDD=gestionnaire;
}

void GestionnaireInteraction::addInteraction(InteractionEntity *interaction, ContactEntity *contact)
{
   if(gestionnaireBDD->insertInteraction(interaction)){
       //on a besoin de cherche l'interaction qu'on vient d'inserer dans la base a partir de la liste
       InteractionEntity * interactionAvecId = findInteraction(interaction);
       ContactInteractionEntity * contactInteraction = new ContactInteractionEntity(0,contact,interactionAvecId);
       cout << "Interaction ajoute dans la liste" << endl;
       if(gestionnaireBDD->insertContactInteraction(contactInteraction)){
            cout << "ContactInteraction ajoute dans la liste" << endl;
       }
       else{
           cerr << "Erreur lors de l'insertion en BDD le contactinteraction n'a pas ete ajoute dans la liste en dur"<< endl;
       }
   }
   else{
     cerr << "Erreur lors de l'insertion en BDD l'interaction n'a pas ete ajoute dans la liste en dur"<< endl;
   }

}


void GestionnaireInteraction::editInteraction(InteractionEntity* interaction, InteractionEntity* interactionModif)
{
    if(gestionnaireBDD->updateInteraction(interaction,interactionModif)){
            interaction->setContenuInteraction(interactionModif->getContenuInteraction());
            cout << "Interaction modifie dans la liste" << endl;
    }
    else{
        cerr << "Erreur lors de l'update en BDD l'interaction n'a pas ete modifie dans la liste en dur"<< endl;

    }


}

void GestionnaireInteraction::deleteInteraction(InteractionEntity* interaction)
{

    if(gestionnaireBDD->deleteInteraction(interaction)){
        if(gestionnaireBDD->isInteractionInList(interaction)){

            auto listInteractionEntity = gestionnaireBDD->getListInteractionEntity();
            auto listContactInteractionEntity = gestionnaireBDD->getListContactInteractionEntity();
            auto listInteractionTodoEntity = gestionnaireBDD->getListInteractionTodoEntity();
            auto listTodoEntity = gestionnaireBDD->getListTodoEntity();

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

            gestionnaireBDD->setListInteractionEntity(listInteractionEntity);
            gestionnaireBDD->setListContactInteractionEntity(listContactInteractionEntity);
            gestionnaireBDD->setListInteractionTodoEntity(listInteractionTodoEntity);
            gestionnaireBDD->setListTodoEntity(listTodoEntity);

        }
        else{
            cout << "L'interaction n'existe pas rien n'a ete fait" << endl;
        }
    }
    else{
        cerr << "Erreur lors du delete de l'interaction les listes en dur n'ont pas ete modifie" << endl;
    }
}

const list<InteractionEntity *> &GestionnaireInteraction::getInteractionList() const
{
    return gestionnaireBDD->getListInteractionEntity();
}

const list<InteractionTodoEntity *> &GestionnaireInteraction::getInteractionTodoList() const
{
    return gestionnaireBDD->getListInteractionTodoEntity();
}

InteractionEntity *GestionnaireInteraction::findInteractionById(int id)
{
    auto itInteraction = std::find_if(gestionnaireBDD->getListInteractionEntity().begin(),gestionnaireBDD->getListInteractionEntity().end(), [id](InteractionEntity *interaction){return  interaction->getIdInteraction()==id;});
    return *itInteraction;
}

InteractionEntity *GestionnaireInteraction::findInteraction(InteractionEntity *interactionRecherche)
{
    auto test = gestionnaireBDD->getListInteractionEntity();

    auto itInteraction = std::find_if(gestionnaireBDD->getListInteractionEntity().begin(),gestionnaireBDD->getListInteractionEntity().end(), [interactionRecherche](InteractionEntity *interaction){return  interaction->getContenuInteraction()==interactionRecherche->getContenuInteraction() && interaction->getDateAjoutInteraction()==interactionRecherche->getDateAjoutInteraction();});
    return *itInteraction;
}
