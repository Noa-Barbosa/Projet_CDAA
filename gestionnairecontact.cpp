#include "gestionnairecontact.h"


GestionnaireContact::GestionnaireContact(GestionnaireBDD *gestionnaire)
{
    gestionnaireBDD=gestionnaire;
}

void GestionnaireContact::addContact(ContactEntity *contact)
{
   gestionnaireBDD->insertContact(contact);

}


void GestionnaireContact::editContact(ContactEntity *contact, ContactEntity *contactEntityModifie)
{
    gestionnaireBDD->updateContact(contact,contactEntityModifie);
}

void GestionnaireContact::deleteContact(ContactEntity* contact)
{

    if(gestionnaireBDD->isContactInList(contact)){

        auto listContactEntity = gestionnaireBDD->getListContactEntity();
        auto listContactInteractionEntity = gestionnaireBDD->getListContactInteractionEntity();
        auto listInteractionEntity = gestionnaireBDD->getListInteractionEntity();


        list<ContactInteractionEntity*> contactInteractionAsupprimer;
        list<InteractionEntity*> interactionAsupprimer;

        for(ContactInteractionEntity* contactInteraction : listContactInteractionEntity)
        {
           if(contactInteraction->getContactEntity()==contact){
               contactInteractionAsupprimer.push_back(contactInteraction);
               interactionAsupprimer.push_back(contactInteraction->getInteractionEntity());
           }
        }

        for(ContactInteractionEntity* interactionContactAsupprimer : contactInteractionAsupprimer)
        {
           listContactInteractionEntity.remove(interactionContactAsupprimer);
        }

        for (InteractionEntity* interactionEntity : interactionAsupprimer)
        {
            listInteractionEntity.remove(interactionEntity);
        }

        listContactEntity.remove(contact);

        gestionnaireBDD->setListContactEntity(listContactEntity);
        gestionnaireBDD->setListContactInteractionEntity(listContactInteractionEntity);
        gestionnaireBDD->setListInteractionEntity(listInteractionEntity);

    }
    else{
        cout << "Le contact n'existe pas rien n'a ete fait" << std::endl<<std::endl;
    }
}

ContactEntity* GestionnaireContact::findContactByNom(string nomContact)
{
    auto itContact = std::find_if(gestionnaireBDD->getListContactEntity().begin(),gestionnaireBDD->getListContactEntity().end(), [nomContact](ContactEntity *contact){return  contact->getNomContact()==nomContact;});
    return *itContact;
}

ContactEntity* GestionnaireContact::findByEntreprise(string entrepriseContact)
{
    auto itContact = std::find_if(gestionnaireBDD->getListContactEntity().begin(),gestionnaireBDD->getListContactEntity().end(), [entrepriseContact](ContactEntity *contact){return  contact->getEntrepriseContact()==entrepriseContact;});
    return *itContact;
}

ContactEntity* GestionnaireContact::findByDateCrea(year_month_day dateCrea)
{
    auto itContact = std::find_if(gestionnaireBDD->getListContactEntity().begin(),gestionnaireBDD->getListContactEntity().end(), [dateCrea](ContactEntity *contact){return  contact->getDateCreaContact()==dateCrea;});
    return *itContact;
}

ContactEntity* GestionnaireContact::findByDateModif(year_month_day dateModif)
{
    auto itContact = std::find_if(gestionnaireBDD->getListContactEntity().begin(),gestionnaireBDD->getListContactEntity().end(), [dateModif](ContactEntity *contact){return  contact->getDateDernModif()==dateModif;});
    return *itContact;
}

ContactEntity* GestionnaireContact::findByDateCreaBetween(year_month_day dateCreaMin, year_month_day dateCreaMax)
{
    auto itContact = std::find_if(gestionnaireBDD->getListContactEntity().begin(),gestionnaireBDD->getListContactEntity().end(), [dateCreaMin, dateCreaMax](ContactEntity *contact){return  contact->getDateCreaContact()>=dateCreaMin && contact->getDateCreaContact()<=dateCreaMax;});
    return *itContact;
}

ContactEntity* GestionnaireContact::findByDateModifBetween(year_month_day dateModifMin, year_month_day dateModifMax)
{
    auto itContact = std::find_if(gestionnaireBDD->getListContactEntity().begin(),gestionnaireBDD->getListContactEntity().end(), [dateModifMin, dateModifMax](ContactEntity *contact){return  contact->getDateDernModif()>=dateModifMin && contact->getDateDernModif()<=dateModifMax;});
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
