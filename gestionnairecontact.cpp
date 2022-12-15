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

ContactEntity *GestionnaireContact::findContactById(int id)
{
    auto itContact = std::find_if(gestionnaireBDD->getListContactEntity().begin(),gestionnaireBDD->getListContactEntity().end(), [id](ContactEntity *contact){return  contact->getIdContact()==id;});
    return *itContact;
}

list<InteractionEntity*> GestionnaireContact::listAllInteractions(ContactEntity *contactEntity)
{
    auto listContactInteractionEntity = gestionnaireBDD->getListContactInteractionEntity();
    list<InteractionEntity*> interaction;

    for(ContactInteractionEntity* contactInteraction : listContactInteractionEntity)
    {
       if(contactInteraction->getContactEntity()->getIdContact()==contactEntity->getIdContact()){
           interaction.push_back(contactInteraction->getInteractionEntity());
       }
    }

    return interaction;
}

list<ContactEntity *> GestionnaireContact::listContactsByFilter(string nom, string entreprise, string dateCrea,string dateCreaMin, string dateCreaMax)
{
    auto listContactAFiltrer = gestionnaireBDD->getListContactEntity();

    if(nom!=""){
        list<ContactEntity *> listContactFiltree;

        for(ContactEntity * contact : listContactAFiltrer){
            if (contact->getNomContact()==nom){
                listContactFiltree.push_back(contact);
            }
        }

        if(listContactFiltree.size()>0){
            listContactAFiltrer=listContactFiltree;
        }

    }

    if(entreprise!=""){
        list<ContactEntity *> listContactFiltree;

        for(ContactEntity * contact : listContactAFiltrer){
            if (contact->getEntrepriseContact()==entreprise){
                listContactFiltree.push_back(contact);
            }
        }

        if(listContactFiltree.size()>0){
            listContactAFiltrer=listContactFiltree;
        }
    }

    if(dateCrea!=""){
        list<ContactEntity *> listContactFiltree;

        //cette partie du code separe la chaine de caractere donne la date de creation en trois parties et la stocke dans un vector
        std::vector<std::string> partiesDate;
        std::string partie;
        std::istringstream dateStream(dateCrea);
        while (std::getline(dateStream, partie, '-'))
        {
           partiesDate.push_back(partie);
        }

        //convertit chacune des trois parties de la date en entier
        int annee = std::stoi(partiesDate.at(2));
        int mois = std::stoi(partiesDate.at(1));
        int jour = std::stoi(partiesDate.at(0));

        //pour creer la date approprie
        year_month_day dateCrea =year{annee}/mois/jour;

        for(ContactEntity * contact : listContactAFiltrer){
            if (contact->getDateCreaContact()==dateCrea){
                listContactFiltree.push_back(contact);
            }
        }

            listContactAFiltrer=listContactFiltree;
    }

    if(dateCreaMin!=""){
        if(dateCreaMax!=""){
            list<ContactEntity *> listContactFiltree;

            //cette partie du code separe la chaine de caractere donne la date de creation minimum en trois parties et la stocke dans un vector
            std::vector<std::string> partiesDateMin;
            std::string partieDateMin;
            std::istringstream dateMinStream(dateCreaMin);
            while (std::getline(dateMinStream, partieDateMin, '-'))
            {
               partiesDateMin.push_back(partieDateMin);
            }

            //convertit chacune des trois parties de la date en entier
            int annee = std::stoi(partiesDateMin.at(2));
            int mois = std::stoi(partiesDateMin.at(1));
            int jour = std::stoi(partiesDateMin.at(0));

            //pour creer la date approprie
            year_month_day dateCreaMin =year{annee}/mois/jour;

            //cette partie du code separe la chaine de caractere donne la date de creation minimum en trois parties et la stocke dans un vector
            std::vector<std::string> partiesDateMax;
            std::string partieDateMax;
            std::istringstream dateMaxStream(dateCreaMax);
            while (std::getline(dateMaxStream, partieDateMax, '-'))
            {
               partiesDateMax.push_back(partieDateMax);
            }

            //convertit chacune des trois parties de la date en entier
            annee = std::stoi(partiesDateMax.at(2));
            mois = std::stoi(partiesDateMax.at(1));
            jour = std::stoi(partiesDateMax.at(0));

            //pour creer la date approprie
            year_month_day dateCreaMax =year{annee}/mois/jour;

            for(ContactEntity * contact : listContactAFiltrer){
                  if(contact->getDateCreaContact()>=dateCreaMin && contact->getDateCreaContact()<= dateCreaMax){
                      listContactFiltree.push_back(contact);
                  }
            }

                listContactAFiltrer=listContactFiltree;
        }
    }

    return listContactAFiltrer;

}

const list<ContactEntity *> &GestionnaireContact::getContactList() const
{
    return gestionnaireBDD->getListContactEntity();
}

const list<ContactInteractionEntity *> &GestionnaireContact::getContactInteractionList() const
{
    return gestionnaireBDD->getListContactInteractionEntity();
}
