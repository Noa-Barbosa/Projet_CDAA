#ifndef GESTIONNAIRECONTACT_H
#define GESTIONNAIRECONTACT_H
#include <iostream>
#include <list>
#include <contactentity.h>
#include <gestionnaireBDD.h>
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
    GestionnaireContact(GestionnaireBDD *gestionnaire);

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
     * @brief Recherche un contact par son identifiant en base
     * @param id l'id du contact
     * @return le contact correpondant dans la liste
     */
    ContactEntity * findContactById(int id);

    /**
    * @brief renvoi la liste de toutes les interactions d'un contact
    * @param contactEntity le contact dont l'on désire la liste des interactions
    * @return la liste des interactions du contact
    */
    list<InteractionEntity*> listAllInteractions(ContactEntity *contactEntity);

    /**
     * @brief Renvoie une liste des contact ayant les valeurs en parametre
     * @param nom le nom a rechercher
     * @param entreprise l'entreprise a rechercher
     * @param dateCrea la dateDeCrea a rechercher
     * @return
     */
    list<ContactEntity *> listContactsByFilter(string nom, string entreprise, string dateCrea, string dateCreaMin, string dateCreaMax);

    /**
    * @brief Assesseur de la date de la dernière suppression de contact
    * @return La date de la dernière suppression d'un contact
     */
    const year_month_day &getDateDernSuppContact() const;

    /**
    * @brief modifie la date de dernière suppression de contact
    */
    void setDateDernSuppContact(const year_month_day &newDateDernSuppContact);

    const list<ContactEntity *> &getContactList() const;

    const list<ContactInteractionEntity *> &getContactInteractionList() const;

    private:

    /**
     * @brief Date de la derniere suppression d'un contact
     */
    year_month_day dateDernSuppContact;

    /**
     * @brief Gestionnaire des listes du programme
     */
    GestionnaireBDD *gestionnaireBDD;
};

#endif // GESTIONNAIRECONTACT_H
