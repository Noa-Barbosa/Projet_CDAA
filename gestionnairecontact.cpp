#include "gestionnairecontact.h"


GestionnaireContact::GestionnaireContact(GestionnaireListes *gestionnaire)
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
        cout << "Le contact existe deja dans la liste elle n'a pas ete ajoute" << std::endl;
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
        auto listInteractionContactEntity = gestionnaireListes->getListContactInteractionEntity();


        list<ContactInteractionEntity*> interactionContactAsupprimer;

        for(ContactInteractionEntity* interactionContact : listInteractionContactEntity)
        {
           if(interactionContact->getContactEntity()==contact){
               interactionContactAsupprimer.push_back(interactionContact);

           }
        }

        for(ContactInteractionEntity* interactionContactAsupprimer : interactionContactAsupprimer)
        {
           listInteractionContactEntity.remove(interactionContactAsupprimer);
        }

        listContactEntity.remove(contact);

        gestionnaireListes->setListContactEntity(listContactEntity);
        gestionnaireListes->setListContactInteractionEntity(listInteractionContactEntity);

    }
    else{
        cout << "Le contact n'existe pas rien n'a ete fait" << std::endl;
    }
}

ContactEntity* GestionnaireContact::findContactByNom(string nomContact)
{
    auto ret = std::find_if(gestionnaireListes->getListContactEntity().begin(),gestionnaireListes->getListContactEntity().end(), [nomContact](ContactEntity *contact){return  contact->getNomContact()==nomContact;});
    return *ret;
}

ContactEntity* GestionnaireContact::findByEntreprise(string entrepriseContact)
{

}

ContactEntity* GestionnaireContact::findByDateCrea(sys_days dateCrea)
{

}

ContactEntity* GestionnaireContact::findByDateModif(sys_days dateModif)
{

}

ContactEntity* GestionnaireContact::findByDateCreaBetween(sys_days dateCreaMin, sys_days dateCreaMax)
{

}

ContactEntity* GestionnaireContact::findByDateModifBetween(sys_days dateModifMin, sys_days dateModifMax)
{

}

list<InteractionEntity> GestionnaireContact::listAllInteractions(ContactEntity *contactEntity)
{

}
