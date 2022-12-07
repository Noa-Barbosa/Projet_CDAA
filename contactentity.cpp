#include "contactentity.h"

ContactEntity::ContactEntity()
{
    dateCreaContact=year_month_day{floor<days>(system_clock::now())};
    dateDernModif=year_month_day{floor<days>(system_clock::now())};
}

ContactEntity::ContactEntity(int id,std::string nom, std::string prenom, std::string entreprise, std::string mail, std::list<unsigned> tel, std::string photo, year_month_day dateCrea, year_month_day dateDern)
{
    idContact = id;
    nomContact=nom;
    prenomContact=prenom;
    entrepriseContact=entreprise;
    mailContact=mail;
    telContact=tel;
    uriPhotoContact=photo;
    dateCreaContact=dateCrea;
    dateDernModif=dateDern;
}

const std::string &ContactEntity::getNomContact() const
{
    return nomContact;
}

void ContactEntity::setNomContact(const std::string &newNomContact)
{
    nomContact = newNomContact;
    dateDernModif=year_month_day{floor<days>(system_clock::now())};
}

const std::string &ContactEntity::getPrenomContact() const
{
    return prenomContact;
}

void ContactEntity::setPrenomContact(const std::string &newPrenomContact)
{
    prenomContact = newPrenomContact;
    dateDernModif=year_month_day{floor<days>(system_clock::now())};
}

const std::string &ContactEntity::getEntrepriseContact() const
{
    return entrepriseContact;
}

void ContactEntity::setEntrepriseContact(const std::string &newEntrepriseContact)
{
    entrepriseContact = newEntrepriseContact;
    dateDernModif=year_month_day{floor<days>(system_clock::now())};
}

const std::string &ContactEntity::getMailContact() const
{
    return mailContact;
}

void ContactEntity::setMailContact(const std::string &newMailContact)
{
    mailContact = newMailContact;
    dateDernModif=year_month_day{floor<days>(system_clock::now())};
}

const std::list<unsigned> &ContactEntity::getTelContact() const
{
    return telContact;
}

void ContactEntity::setTelContact(const std::list<unsigned> &newTelContact)
{
    telContact = newTelContact;
    dateDernModif=year_month_day{floor<days>(system_clock::now())};
}

const year_month_day &ContactEntity::getDateCreaContact() const
{
    return dateCreaContact;
}

int ContactEntity::getIdContact() const
{
    return idContact;
}

const year_month_day &ContactEntity::getDateLastUpdate() const
{
    return dateDernModif;
}

void ContactEntity::setDateLastUpdate(const year_month_day &newDateLastUpdate)
{
    dateDernModif = newDateLastUpdate;
}


const std::string &ContactEntity::getPhotoContact() const
{
    return uriPhotoContact;
}

void ContactEntity::setPhotoContact(const std::string &newPhotoContact)
{
    uriPhotoContact = newPhotoContact;
    dateDernModif=year_month_day{floor<days>(system_clock::now())};
}

std::ostream& operator<< (std::ostream& os, const ContactEntity& contact){
    os << contact.idContact << ' '<<contact.nomContact << ' ' << contact.prenomContact << ' ' << contact.entrepriseContact << ' ' << contact.mailContact << ' ' << "telephone" << ' ' << contact.dateCreaContact << ' ' << contact.uriPhotoContact;
    return os;
}

bool operator==(ContactEntity a, ContactEntity b){
    return a.dateCreaContact == b.dateCreaContact &&
            a.dateDernModif == b.dateDernModif &&
            a.entrepriseContact == b.entrepriseContact &&
            a.idContact == b.idContact &&
            a.mailContact == b.mailContact &&
            a.nomContact == b.nomContact &&
            a.prenomContact == b.prenomContact &&
            a.telContact == b.telContact &&
            a.uriPhotoContact == b.uriPhotoContact;
}

