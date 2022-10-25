#ifndef GESTIONNAIRECONTACT_H
#define GESTIONNAIRECONTACT_H
#include <iostream>
#include <list>
#include <contactentity.h>

/**
*@brief classe faisant la liason entre le programme et la BDD, permettant de gérer les contacts de la BDD 
*/

class GestionnaireContact
{
public:
    /**
         * @brief Constructeur vide de la fiche
         */
    GestionnaireContact();

    /**
     * @brief ajouter un contact à la BDD
     * @param le contact à ajouter
     */
    void addContact(ContactEntity contactEntity);

    /**
     * @brief editer un contact de la BDD
     * @param l'id du contact à modifier
     * @param la modification du contact
     */
    void editContact(int idContactEntity, ContactEntity contactEntity);

    /**
     * @brief supprimmer un contact de la BDD
     * @param l'id du contact à supprimmer
     */
    void deleteContact(ContactEntity idContactEntity);

    /**
     * @brief trouver un contact avec son nom
     * @param le nom du contact
     */
    ContactEntity findContactByNom(string nomContact);

    /**
     * @brief trouver un contact avec son entreprise
     * @param l'entreprise du contact
     */
    ContactEntity findByEntreprise(string entrepriseContact);

    /**
     * @brief lister les contacts par ordre alphabétique
     * @param la liste des contacts
     */
    list<ContactEntity> sortByAlphabeticalOrder(list<ContactEntity> listContacts);

    /**
     * @brief lister les contacts par date de création
     * @param la liste des contacts
     */
    list<ContactEntity> sortByDate(list<ContactEntity> listContacts);

};

#endif // GESTIONNAIRECONTACT_H