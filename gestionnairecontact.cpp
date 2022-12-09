#include "gestionnairecontact.h"


GestionnaireContact::GestionnaireContact(GestionnaireBDD *gestionnaire)
{
    gestionnaireBDD=gestionnaire;
}

void GestionnaireContact::addContact(ContactEntity *contact)
{

   if(gestionnaireBDD->insertContact(contact)){
        cout << "Contact ajoute dans la liste" << endl;
   }
   else{
       cerr << "Erreur lors de l'insertion en BDD le contact n'a pas ete ajoute dans la liste en dur"<< endl;
   }

}


void GestionnaireContact::editContact(ContactEntity *contact, ContactEntity *contactEntityModifie)
{
    if(gestionnaireBDD->updateContact(contact,contactEntityModifie)){
            contact->setNomContact(contactEntityModifie->getNomContact());
            contact->setPrenomContact(contactEntityModifie->getPrenomContact());
            contact->setEntrepriseContact(contactEntityModifie->getEntrepriseContact());
            contact->setTelContact(contactEntityModifie->getTelContact());
            contact->setMailContact(contactEntityModifie->getMailContact());
            contact->setPhotoContact(contactEntityModifie->getPhotoContact());
            contact->setDateDernModif(year_month_day{floor<days>(system_clock::now())});
            cout << "Contact modifie dans la liste" << endl;
    }
    else{
        cerr << "Erreur lors de l'update en BDD le contact n'a pas ete modifie dans la liste en dur"<< endl;

    }


}

void GestionnaireContact::deleteContact(ContactEntity* contact)
{

    if(gestionnaireBDD->deleteContact(contact)){
        if(gestionnaireBDD->isContactInList(contact)){

            auto listContactEntity = gestionnaireBDD->getListContactEntity();
            auto listContactInteractionEntity = gestionnaireBDD->getListContactInteractionEntity();
            auto listInteractionEntity = gestionnaireBDD->getListInteractionEntity();
            auto listInteractionTodoEntity = gestionnaireBDD->getListInteractionTodoEntity();
            auto listTodoEntity = gestionnaireBDD->getListTodoEntity();


            list<ContactInteractionEntity*> contactInteractionAsupprimer;
            list<InteractionEntity*> interactionAsupprimer;

            for(ContactInteractionEntity* contactInteraction : listContactInteractionEntity)
            {
               if(contactInteraction->getIdContactEntity()==contact->getIdContact()){
                   contactInteractionAsupprimer.push_back(contactInteraction);
                   interactionAsupprimer.push_back(contactInteraction->getInteractionEntity());
               }
            }


            for(ContactInteractionEntity* interactionContactAsupprimer : contactInteractionAsupprimer)
            {
               listContactInteractionEntity.remove(interactionContactAsupprimer);
            }

            list<InteractionTodoEntity*> interactionTodoAsupprimer;
            list<TodoEntity*> todoAsupprimer;

            for (InteractionEntity* interactionEntity : interactionAsupprimer)
            {
                listInteractionEntity.remove(interactionEntity);
                for(InteractionTodoEntity* interactionTodoEntity : listInteractionTodoEntity){
                    if(interactionTodoEntity->getIdInteraction()==interactionEntity->getIdInteraction()){
                        interactionTodoAsupprimer.push_back(interactionTodoEntity);
                        todoAsupprimer.push_back(interactionTodoEntity->getTodoEntity());
                    }
                }
            }

            for(InteractionTodoEntity* interactionTodo : interactionTodoAsupprimer)
            {
               listInteractionTodoEntity.remove(interactionTodo);
            }

            for(TodoEntity* todo : todoAsupprimer){
                listTodoEntity.remove(todo);
            }

            listContactEntity.remove(contact);

            //il faut remettre à jour les listes dans le gestionnaireBDD après les avoir modifie
            gestionnaireBDD->setListContactEntity(listContactEntity);
            gestionnaireBDD->setListContactInteractionEntity(listContactInteractionEntity);
            gestionnaireBDD->setListInteractionEntity(listInteractionEntity);
            gestionnaireBDD->setListInteractionTodoEntity(listInteractionTodoEntity);
            gestionnaireBDD->setListTodoEntity(listTodoEntity);

        }
        else{
            cerr << "Le contact n'existe pas rien n'a ete fait" << endl;
        }
    }
    else{
         cerr << "Erreur lors du delete du contact les listes en dur n'ont pas ete modifie" << endl;
    }

}

ContactEntity* GestionnaireContact::findContactByNom(string nomContact)
{
    auto itContact = std::find_if(gestionnaireBDD->getListContactEntity().begin(),gestionnaireBDD->getListContactEntity().end(), [nomContact](ContactEntity *contact){return  contact->getNomContact()==nomContact;});
    return *itContact;
}

ContactEntity* GestionnaireContact::findContactByEntreprise(string entrepriseContact)
{
    auto itContact = std::find_if(gestionnaireBDD->getListContactEntity().begin(),gestionnaireBDD->getListContactEntity().end(), [entrepriseContact](ContactEntity *contact){return  contact->getEntrepriseContact()==entrepriseContact;});
    return *itContact;
}

ContactEntity* GestionnaireContact::findContactByDateCrea(year_month_day dateCrea)
{
    auto itContact = std::find_if(gestionnaireBDD->getListContactEntity().begin(),gestionnaireBDD->getListContactEntity().end(), [dateCrea](ContactEntity *contact){return  contact->getDateCreaContact()==dateCrea;});
    return *itContact;
}

ContactEntity* GestionnaireContact::findContactByDateModif(year_month_day dateModif)
{
    auto itContact = std::find_if(gestionnaireBDD->getListContactEntity().begin(),gestionnaireBDD->getListContactEntity().end(), [dateModif](ContactEntity *contact){return  contact->getDateDernModif()==dateModif;});
    return *itContact;
}

ContactEntity* GestionnaireContact::findContactByDateCreaBetween(year_month_day dateCreaMin, year_month_day dateCreaMax)
{
    auto itContact = std::find_if(gestionnaireBDD->getListContactEntity().begin(),gestionnaireBDD->getListContactEntity().end(), [dateCreaMin, dateCreaMax](ContactEntity *contact){return  contact->getDateCreaContact()>=dateCreaMin && contact->getDateCreaContact()<=dateCreaMax;});
    return *itContact;
}

ContactEntity* GestionnaireContact::findContactByDateModifBetween(year_month_day dateModifMin, year_month_day dateModifMax)
{
    auto itContact = std::find_if(gestionnaireBDD->getListContactEntity().begin(),gestionnaireBDD->getListContactEntity().end(), [dateModifMin, dateModifMax](ContactEntity *contact){return  contact->getDateDernModif()>=dateModifMin && contact->getDateDernModif()<=dateModifMax;});
    return *itContact;
}

ContactEntity *GestionnaireContact::findContactById(int id)
{
    auto itContact = std::find_if(gestionnaireBDD->getListContactEntity().begin(),gestionnaireBDD->getListContactEntity().end(), [id](ContactEntity *contact){return  contact->getIdContact()==id;});
    return *itContact;
}

ContactEntity *GestionnaireContact::findContactByMail(string mail)
{
    auto itContact = std::find_if(gestionnaireBDD->getListContactEntity().begin(),gestionnaireBDD->getListContactEntity().end(), [mail](ContactEntity *contact){return  contact->getMailContact()==mail;});
    return *itContact;
}

list<InteractionEntity*> GestionnaireContact::listAllInteractions(ContactEntity *contactEntity)
{
    auto listContactInteractionEntity = gestionnaireBDD->getListContactInteractionEntity();
    list<InteractionEntity*> interaction;

    for(ContactInteractionEntity* contactInteraction : listContactInteractionEntity)
    {
       if(contactInteraction->getContactEntity()==contactEntity){
           interaction.push_back(contactInteraction->getInteractionEntity());
       }
    }

    return interaction;
}

const list<ContactEntity *> &GestionnaireContact::getContactList() const
{
    return gestionnaireBDD->getListContactEntity();
}

const list<ContactInteractionEntity *> &GestionnaireContact::getContactInteractionList() const
{
    return gestionnaireBDD->getListContactInteractionEntity();
}
