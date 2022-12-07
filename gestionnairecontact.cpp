#include "gestionnairecontact.h"


GestionnaireContact::GestionnaireContact(GestionnaireBDD *gestionnaire)
{
    gestionnaireListes=gestionnaire;
}

void GestionnaireContact::addContact(ContactEntity *contact)
{
    //a chaque fois qu'on veut faire une ajouter un contact on recupere la liste des contacts actuel avec le gestionnaire de liste (plus tard ce sera un appel sur la base)
    auto listContactEntity = gestionnaireListes->getListContactEntity();

    //si l'interaction n'existe pas deja dans la liste
    if(!gestionnaireListes->isContactInList(contact)){

        listContactEntity.push_back(contact);

        gestionnaireListes->setListContactEntity(listContactEntity);

    }
    else{
        cout << "Le contact existe deja dans la liste elle n'a pas ete ajoute" << std::endl<<std::endl;
    }

}


void GestionnaireContact::editContact(ContactEntity *contact, ContactEntity *contactEntityModifie)
{

    contact->setNomContact(contactEntityModifie->getNomContact());
    contact->setPrenomContact(contactEntityModifie->getPrenomContact());
    contact->setEntrepriseContact(contactEntityModifie->getEntrepriseContact());
    contact->setTelContact(contactEntityModifie->getTelContact());
    contact->setMailContact(contactEntityModifie->getMailContact());
    contact->setPhotoContact(contactEntityModifie->getPhotoContact());
    contact->setDateLastUpdate(floor<days>(system_clock::now()));

}

void GestionnaireContact::deleteContact(ContactEntity* contact)
{

    if(gestionnaireListes->isContactInList(contact)){

        auto listContactEntity = gestionnaireListes->getListContactEntity();
        auto listContactInteractionEntity = gestionnaireListes->getListContactInteractionEntity();
        auto listInteractionEntity = gestionnaireListes->getListInteractionEntity();


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

        gestionnaireListes->setListContactEntity(listContactEntity);
        gestionnaireListes->setListContactInteractionEntity(listContactInteractionEntity);
        gestionnaireListes->setListInteractionEntity(listInteractionEntity);

    }
    else{
        cout << "Le contact n'existe pas rien n'a ete fait" << std::endl<<std::endl;
    }
}

ContactEntity* GestionnaireContact::findContactByNom(string nomContact)
{
    auto itContact = std::find_if(gestionnaireListes->getListContactEntity().begin(),gestionnaireListes->getListContactEntity().end(), [nomContact](ContactEntity *contact){return  contact->getNomContact()==nomContact;});
    return *itContact;
}

ContactEntity* GestionnaireContact::findByEntreprise(string entrepriseContact)
{
    auto itContact = std::find_if(gestionnaireListes->getListContactEntity().begin(),gestionnaireListes->getListContactEntity().end(), [entrepriseContact](ContactEntity *contact){return  contact->getEntrepriseContact()==entrepriseContact;});
    return *itContact;
}

ContactEntity* GestionnaireContact::findByDateCrea(year_month_day dateCrea)
{
    auto itContact = std::find_if(gestionnaireListes->getListContactEntity().begin(),gestionnaireListes->getListContactEntity().end(), [dateCrea](ContactEntity *contact){return  contact->getDateCreaContact()==dateCrea;});
    return *itContact;
}

ContactEntity* GestionnaireContact::findByDateModif(year_month_day dateModif)
{
    auto itContact = std::find_if(gestionnaireListes->getListContactEntity().begin(),gestionnaireListes->getListContactEntity().end(), [dateModif](ContactEntity *contact){return  contact->getDateLastUpdate()==dateModif;});
    return *itContact;
}

ContactEntity* GestionnaireContact::findByDateCreaBetween(year_month_day dateCreaMin, year_month_day dateCreaMax)
{
    auto itContact = std::find_if(gestionnaireListes->getListContactEntity().begin(),gestionnaireListes->getListContactEntity().end(), [dateCreaMin, dateCreaMax](ContactEntity *contact){return  contact->getDateCreaContact()>=dateCreaMin && contact->getDateCreaContact()<=dateCreaMax;});
    return *itContact;
}

ContactEntity* GestionnaireContact::findByDateModifBetween(year_month_day dateModifMin, year_month_day dateModifMax)
{
    auto itContact = std::find_if(gestionnaireListes->getListContactEntity().begin(),gestionnaireListes->getListContactEntity().end(), [dateModifMin, dateModifMax](ContactEntity *contact){return  contact->getDateLastUpdate()>=dateModifMin && contact->getDateLastUpdate()<=dateModifMax;});
    return *itContact;
}

list<InteractionEntity*> GestionnaireContact::listAllInteractions(ContactEntity *contactEntity)
{
    auto listContactInteractionEntity = gestionnaireListes->getListContactInteractionEntity();
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
    return gestionnaireListes->getListContactEntity();
}
