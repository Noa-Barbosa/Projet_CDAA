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
    ContactEntity* findContactByEntreprise(string entrepriseContact);

    /**
    * @brief trouver un contact par sa date de création
    * @param dateCrea la date de création
    * @return le contact
    */
    ContactEntity* findContactByDateCrea(year_month_day dateCrea);

    /**
    * @brief trouver un contact par sa date de modification
    * @param dateModif la date de modification
    * @return le contact
    */
    ContactEntity* findContactByDateModif(year_month_day dateModif);

    /**
    * @brief renvoi le premier contact trouver entre deux date de creation
    * @param dateCreaMin la date de création minimun
    * @param dateCreaMax la date de création maximum
    * @return le contact
    */
    ContactEntity* findContactByDateCreaBetween(year_month_day dateCreaMin, year_month_day dateCreaMax);

    /**
    * @brief renvoi le premier contact trouver entre deux date de modification
    * @param dateModifMin la date de modification minimum
    * @param dateModifMax la date de modification maximum
    * @return le contact
    */
    ContactEntity* findContactByDateModifBetween(year_month_day dateModifMin, year_month_day dateModifMax);

    /**
     * @brief Recherche un contact par son identifiant en base
     * @param id l'id du contact
     * @return le contact correpondant dans la liste
     */
    ContactEntity * findContactById(int id);

    /**
     * @brief Recherche un contact par son adresse email unique
     * @param mail l'adresse email unique du contact
     * @return le contact qui correspond dans la liste
     */
    ContactEntity *findContactByMail(string mail);

    /**
    * @brief renvoi la liste de toutes les interactions d'un contact
    * @param contactEntity le contact dont l'on désire la liste des interactions
    * @return la liste des interactions du contact
    */
    list<InteractionEntity*> listAllInteractions(ContactEntity *contactEntity);

    /**
     * @brief Verifie si le contact existe ou pas dans la liste des contacts
     * @param contactRecherche Le contact recherche
     * @return vrai s'il existe faux sinon
     */
    bool isContactInList(ContactEntity *contactRecherche);

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
