#ifndef GESTIONNAIRECONTACT_H
#define GESTIONNAIRECONTACT_H
#include <iostream>
#include <list>
#include <contactentity.h>
#include <gestionnairelistes.h>
#include <date.h>

/**
*@brief classe faisant la liason entre le programme et la BDD, permettant de gérer les contacts de la BDD
*/

class GestionnaireContact
{
public:
    /**
    * @brief Constructeur de la fiche
    * @param gestionnaire gestionnaire des listes
    */
    GestionnaireContact(GestionnaireListes *gestionnaire);

    /**
    * @brief ajouter un contact à la BDD
    * @param contactEntity un pointeur vers le contact à ajouter
    */
    void addContact(ContactEntity *contactEntity);

    /**
    * @brief editer un contact de la BDD
    * @param contactEntity le contact à modifier
    * @param contactEntityModifie la modification du contact
    */
    void editContact(ContactEntity *contactEntity, ContactEntity *contactEntityModifie);

    /**
    * @brief supprimmer un contact de la BDD
    * @param contactEntity le contact à supprimmer
    */
    void deleteContact(ContactEntity *contactEntity);

    /**
    * @brief trouver un contact avec son nom
    * @param nomContact le nom du contact
    * @return le contact
    */
    ContactEntity* findContactByNom(string nomContact);

    /**
    * @brief trouver un contact avec son entreprise
    * @param entrepriseContact l'entreprise du contact
    * @return le contact
    */
    ContactEntity* findByEntreprise(string entrepriseContact);

    /**
    * @brief trouver un contact par sa date de création
    * @param dateCrea la date de création
    * @return le contact
    */
    ContactEntity* findByDateCrea(sys_days dateCrea);

    /**
    * @brief trouver un contact par sa date de modification
    * @param dateModif la date de modification
    * @return le contact
    */
    ContactEntity* findByDateModif(sys_days dateModif);

    /**
    * @brief renvoi le premier contact trouver entre deux date de création
    * @param dateCreaMin la date de création minimun
    * @param dateCreaMax la date de création maximum
    * @return le contact
    */
    ContactEntity* findByDateCreaBetween(sys_days dateCreaMin, sys_days dateCreaMax);

    /**
    * @brief renvoi le premier contact trouver entre deux date de modification
    * @param dateModifMin la date de modification minimum
    * @param dateModifMax la date de modification maximum
    * @return le contact
    */
    ContactEntity* findByDateModifBetween(sys_days dateModifMin, sys_days dateModifMax);

    /**
    * @brief renvoi la liste de toutes les interactions d'un contact
    * @param contactEntity le contact dont l'on désire la liste des interactions
    * @return la liste des interactions du contact
    */
    list<InteractionEntity*> listAllInteractions(ContactEntity *contactEntity);

    /**
    * @brief Assesseur de la date de la dernière suppression de contact
    * @return La date de la dernière suppression d'un contact
     */
    const sys_days &getDateDernSuppContact() const;

    /**
    * @brief modifie la date de dernière suppression de contact
    */
    void setDateDernSuppContact(const sys_days &newDateDernSuppContact);

    private:

    sys_days dateDernSuppContact;
    GestionnaireListes *gestionnaireListes;
};

#endif // GESTIONNAIRECONTACT_H
