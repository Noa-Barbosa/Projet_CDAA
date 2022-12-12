#include "contactform.h"
#include "ui_contactform.h"
#include "contactentity.h"
#include "QMessageBox"

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

    //vérification des contraintes
    QMessageBox messageBox;
    if(nom.empty()){
        messageBox.information(this, "Champ invalide","Le champ nom ne doit pas être vide");
        messageBox.setFixedSize(500,200);
    }else if(prenom.empty()){
        messageBox.information(this, "Champ invalide","Le champ prénom ne doit pas être vide");
        messageBox.setFixedSize(500,200);
    }else if(entreprise.empty()){
        messageBox.information(this, "Champ invalide","Le champ entreprise ne doit pas être vide");
        messageBox.setFixedSize(500,200);
    }else if(mail.empty()){
        messageBox.information(this, "Champ invalide","Le champ mail ne doit pas être vide");
        messageBox.setFixedSize(500,200);
    }else if(mail.find("@")!=true){
        messageBox.information(this, "Champ invalide","Le champ mail doit être semblable à exemple@gmail.fr");
        messageBox.setFixedSize(500,200);
    }else if(telString.empty()){
        messageBox.information(this, "Champ invalide","Le champ téléphone ne doit pas être vide");
        messageBox.setFixedSize(500,200);
    }else if((telString.find_first_of("0123456789") == string::npos)or(telString.size()!=10)){
        messageBox.information(this, "Champ invalide","Le champ téléphone doit contenir 10 chiffres");
        messageBox.setFixedSize(500,200);
    }
    else {
        //ajout ou modification
        if(mod==false){

            gestionnairecontact->addContact(contact);
            emit signalEnregistrement();
        }else if(mod==true){
            gestionnairecontact->editContact(contactentity,contact);
            emit signalEnregistrement();
        }
    }



}


void ContactForm::on_annulerPb_clicked()
{
    this->close();
}

