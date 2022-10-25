#ifndef CONTACTENTITY_H
#define CONTACTENTITY_H
#include <iostream>
#include <date.h>
#include <list>
#include <interactionentity.h>

using namespace date;
using namespace std;
using namespace std::chrono;
/**
 * @brief Classe decrivant une fiche de contact du CRM
 */
class ContactEntity
{

public:
    /**
     * @brief Constructeur vide de la fiche
     */
    ContactEntity();

    /**
     * @brief Constructeur parametrique d'un contact
     * @param nom le nom du contact
     * @param prenom le prenom du contact
     * @param entreprise l'entreprise du contact
     * @param mail le mail du contact
     * @param tel le numero de telephone du contact
     * @param photo l'uri de la photo du contact
     */
    ContactEntity(string nom, string prenom, string entreprise, string mail, list<unsigned> tel, string photo);

    ~ContactEntity(){
        telContact.clear();
    }
    /**
     * @brief Assesseur du nom du contact
     * @return Le nom du contact qui est une chaine de caractere
     */
    const string &getNomContact() const;
    /**
     * @brief Mutateur du nom du contact
     * @param La chaine de caratere du nouveau nom
     */
    void setNomContact(const string &newNomContact);

    /**
     * @brief Assesseur du prenom du contact
     * @return La chaine de caratere du prenom
     */
    const string &getPrenomContact() const;
    /**
     * @brief Mutateur du prenom du contact
     * @param La chaine de caractere du nouveau prenom
     */
    void setPrenomContact(const string &newPrenomContact);

    /**
     * @brief Assesseur de l'entreprise du contact
     * @return La chaine de caractere de l'entreprise
     */
    const string &getEntrepriseContact() const;
    /**
     * @brief Mutateur de l'entreprise du contact
     * @param La nouvelle entreprise
     */
    void setEntrepriseContact(const string &newEntrepriseContact);

    /**
     * @brief Assesseur de l'adresse mail du contact
     * @return La chaine de caractere de l'adresse mail
     */
    const string &getMailContact() const;
    /**
     * @brief Mutateur de l'adresse mail
     * @param le nouveau mail du contact
     */
    void setMailContact(const string &newMailContact);

    /**
     * @brief Assesseur du tel du contact
     * @return une liste d'entier non signe correspondant au numero de telephone du contact
     */
    const std::list<unsigned> &getTelContact() const;
    /**
     * @brief Mutateur du tel du contact
     * @param la liste d'entier non signe correspondant au nouveau numero de telephone
     */
    void setTelContact(const std::list<unsigned> &newTelContact);

    /**
     * @brief Assesseur de l'uri du la photo du contact
     * @return l'uri de la photo
     */
    const string &getPhotoContact() const;
    /**
     * @brief Mutateur de la photo du contact
     * @param l'uri de la nouvelle photo du contact
     */
    void setPhotoContact(const string &newPhotoContact);

    /**
     * @brief Assesseur de la date de creation du contact
     * @return la date de creation
     */
    const sys_days &getDateCreaContact() const;

    /**
     * @brief getListInteraction
     * @return
     */
    const list<InteractionEntity> &getListInteraction() const;

    /**
    * @brief Assesseur de l'id du contact
    * @return l'entier de l'id
    */
    int getIdContact() const;

    /**
     * @brief Assesseur de la date de la derniere modification
     * @return la date de la derniere modification
     */
    const sys_days &getDateLastUpdate() const;

    /**
     * @brief Mutateur de la derniere date de modification
     * @param la nouvel date de derniere modifcation
     */
    void setDateLastUpdate(const sys_days &newDateLastUpdate);

private:

    /**
     * @brief Id du contact dans la BDD (plus tard il sera fixer automatiquement apres l'ajout dans la BDD SQL-Lite avec l'auto-increment)
     */
    int idContact;

    /**
    * @brief Le nom du contact
    */
    string nomContact;

    /**
    * @brief Le prenom du contact
    */
    string prenomContact;

    /**
    * @brief L'entreprise du contact
    */
    string entrepriseContact;

    /**
    * @brief L'adresse mail du contact
    */
    string mailContact;

    /**
    * @brief Le numéro de telephone du contact
    */
    list<unsigned> telContact;

    /**
    * @brief La photo du contact
    */
    string uriPhotoContact;

    /**
    * @brief La date de creation du contact
    */
    sys_days dateCreaContact;

    /**
     * @brief La date de la derniere maj du contact
     */
    sys_days dateLastUpdate;

    /**
   * @brief Fonction amie qui surcharge l'operateur << pour l'affichage du contact
   */
    friend std::ostream& operator<< (ostream& os, const ContactEntity& contact);

    friend bool operator==(ContactEntity a, ContactEntity b);
};

#endif // CONTACTENTITY_H
