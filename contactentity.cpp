#include "contactentity.h"

ContactEntity::ContactEntity()
{
    dateCreaContact=floor<days>(system_clock::now());
    dateLastUpdate=floor<days>(system_clock::now());
}

ContactEntity::ContactEntity(std::string nom, std::string prenom, std::string entreprise, std::string mail, std::list<unsigned> tel, std::string photo)
{
    nomContact=nom;
    prenomContact=prenom;
    entrepriseContact=entreprise;
    mailContact=mail;
    telContact=tel;
    uriPhotoContact=photo;
    dateCreaContact=floor<days>(system_clock::now());
    dateLastUpdate=floor<days>(system_clock::now());
}

const std::string &ContactEntity::getNomContact() const
{
    return nomContact;
}

void ContactEntity::setNomContact(const std::string &newNomContact)
{
    nomContact = newNomContact;
    dateLastUpdate=floor<days>(system_clock::now());
}

const std::string &ContactEntity::getPrenomContact() const
{
    return prenomContact;
}

void ContactEntity::setPrenomContact(const std::string &newPrenomContact)
{
    prenomContact = newPrenomContact;
    dateLastUpdate=floor<days>(system_clock::now());
}

const std::string &ContactEntity::getEntrepriseContact() const
{
    return entrepriseContact;
}

void ContactEntity::setEntrepriseContact(const std::string &newEntrepriseContact)
{
    entrepriseContact = newEntrepriseContact;
    dateLastUpdate=floor<days>(system_clock::now());
}

const std::string &ContactEntity::getMailContact() const
{
    return mailContact;
}

void ContactEntity::setMailContact(const std::string &newMailContact)
{
    mailContact = newMailContact;
    dateLastUpdate=floor<days>(system_clock::now());
}

const std::list<unsigned> &ContactEntity::getTelContact() const
{
    return telContact;
}

void ContactEntity::setTelContact(const std::list<unsigned> &newTelContact)
{
    telContact = newTelContact;
    dateLastUpdate=floor<days>(system_clock::now());
}

const sys_days &ContactEntity::getDateCreaContact() const
{
    return dateCreaContact;
}

int ContactEntity::getIdContact() const
{
    return idContact;
}

const sys_days &ContactEntity::getDateLastUpdate() const
{
    return dateLastUpdate;
}

void ContactEntity::setDateLastUpdate(const sys_days &newDateLastUpdate)
{
    dateLastUpdate = newDateLastUpdate;
}


const std::string &ContactEntity::getPhotoContact() const
{
    return uriPhotoContact;
}

void ContactEntity::setPhotoContact(const std::string &newPhotoContact)
{
    uriPhotoContact = newPhotoContact;
    dateLastUpdate=floor<days>(system_clock::now());
}

std::ostream& operator<< (std::ostream& os, const ContactEntity& contact){
    os << contact.idContact << ' '<<contact.nomContact << ' ' << contact.prenomContact << ' ' << contact.entrepriseContact << ' ' << contact.mailContact << ' ' << "telephone" << ' ' << contact.dateCreaContact << ' ' << contact.uriPhotoContact;
    return os;
}


