#include "contactform.h"
#include "ui_contactform.h"
#include "contactentity.h"

ContactForm::ContactForm(QWidget *parent, GestionnaireContact* gestionnairecontact, GestionnaireInteraction* gestionnaireinteraction, GestionnaireTodo* gestionnairetodo, ContactEntity* contactentity, bool mod) :
    QMainWindow(parent),
    ui(new Ui::contactform)
{
    ui->setupUi(this);
    this->gestionnairecontact = gestionnairecontact;
    this->gestionnaireinteraction = gestionnaireinteraction;
    this->gestionnairetodo = gestionnairetodo;
    this->contactentity = contactentity;
    this->mod = mod;
    ui->NomlineEdit->setText(QString::fromStdString(contactentity->getNomContact()));
    ui->PrenomlineEdit->setText(QString::fromStdString(contactentity->getPrenomContact()));
    ui->EntrepriselineEdit->setText(QString::fromStdString(contactentity->getEntrepriseContact()));
    ui->MaillineEdit->setText(QString::fromStdString(contactentity->getMailContact()));
    //photo
    QPixmap pixmap(QString::fromStdString(contactentity->getPhotoContact()));
    //QPixmap pixmap("C:/Users/Adrien/Desktop/meme creation/Marzad.png");
    ui->PhotolineEdit->setText(QString::fromStdString(contactentity->getPhotoContact()));
    ui->photo->setPixmap(pixmap);
    //pour le numero de telephone il faut envoyer chacun des chiffres dans un stream qu'on convertit ensuite en string
    list<unsigned> listeNumeros = contactentity->getTelContact();
    stringstream streamChiffres;
    string tel;
    for (unsigned &chiffre : listeNumeros){
        streamChiffres << chiffre;
    }
    streamChiffres >> tel;
    ui->TellineEdit->setText(QString::fromStdString(tel));
    //meme choses pour les dates
    year_month_day dateCrea = contactentity->getDateCreaContact();
    stringstream streamDateCrea;
    string chaineDateCrea;
    streamDateCrea << dateCrea;
    streamDateCrea >> chaineDateCrea;
    ui->DateCrea->setText(QString::fromStdString(chaineDateCrea));

    year_month_day dateDernModif = contactentity->getDateDernModif();
    stringstream streamDateDernModif;
    string chaineDateDernModif;
    streamDateDernModif << dateDernModif;
    streamDateDernModif >> chaineDateDernModif;
    ui->DateModif->setText(QString::fromStdString(chaineDateDernModif));
}

ContactForm::~ContactForm()
{
    delete ui;
}

void ContactForm::on_enregisterPb_clicked()
{
    std::string nom = ui->NomlineEdit->text().toStdString();
    std::string prenom = ui->PrenomlineEdit->text().toStdString();
    std::string entreprise = ui->EntrepriselineEdit->text().toStdString();
    std::string telString = ui->TellineEdit->text().toStdString();
    std::string mail = ui->MaillineEdit->text().toStdString();
    std::string photo = ui->PhotolineEdit->text().toStdString();
    ContactEntity* contact = new ContactEntity();
    contact->setNomContact(nom);
    contact->setPrenomContact(prenom);
    contact->setEntrepriseContact(entreprise);
    contact->setMailContact(mail);
    contact->setPhotoContact(photo);
    //telephone
    list<unsigned>  telList;
    for (char &chiffre : telString) {
            telList.push_back((unsigned) chiffre - '0');
        }
    contact->setTelContact(telList);

    //ajout ou modification
    if(mod==false){

        gestionnairecontact->addContact(contact);
    }else if(mod==true){
        gestionnairecontact->editContact(contactentity,contact);
    }


}


void ContactForm::on_annulerPb_clicked()
{
    this->close();
}

