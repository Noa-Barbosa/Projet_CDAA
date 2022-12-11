#include "listcontact.h"
#include "ui_listcontact.h"
#include "gestionnairecontact.h"
#include "contactform.h"
#include "deletecontactwarning.h"



ListContact::ListContact(QWidget *parent, GestionnaireContact* gestionnairecontact, GestionnaireInteraction* gestionnaireinteraction, GestionnaireTodo* gestionnairetodo) :
    QMainWindow(parent),
    ui(new Ui::ListContact)
{
    ui->setupUi(this);
    this->gestionnairecontact = gestionnairecontact;
    this->gestionnaireinteraction = gestionnaireinteraction;
    this->gestionnairetodo = gestionnairetodo;

    ui->dateCreaMinEdit->setEnabled(false);
    ui->dateCreaMaxEdit->setEnabled(false);
    ui->filtreDateCrea->setEnabled(false);

    afficher_liste();

}

ListContact::~ListContact()
{
    delete ui;
}

void ListContact::afficher_liste(string filtreNom, string filtreEntreprise, string filtreDateCrea, string filtreDateCreaMin, string filtreDateCreaMax)
{
     ui->DataListContact->setRowCount(0);
     ui->DataListContact->setColumnHidden(5, true);
    //récupère les données
    list<ContactEntity *> listContact;
    listContact = gestionnairecontact->listContactsByFilter(filtreNom,filtreEntreprise,filtreDateCrea,filtreDateCreaMin,filtreDateCreaMax);

    //insére les données dans la table
    for(ContactEntity* ce : listContact)
    {
        ui->DataListContact->insertRow(0);
        ui->DataListContact->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(ce->getNomContact())));
        ui->DataListContact->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(ce->getPrenomContact())));
        ui->DataListContact->setItem(0, 2, new QTableWidgetItem(QString::fromStdString(ce->getEntrepriseContact())));
        ui->DataListContact->setItem(0, 3, new QTableWidgetItem(QString::fromStdString(ce->getMailContact())));
        ui->DataListContact->setItem(0, 5, new QTableWidgetItem(QString::number(ce->getIdContact())));
        //string pour les dates
        year_month_day dateCrea = ce->getDateCreaContact();

        stringstream streamDateCrea;
        string chaineDateCrea;
        streamDateCrea << dateCrea.day();
        streamDateCrea << "-";
        streamDateCrea << dateCrea.month();
        streamDateCrea << "-";
        streamDateCrea << dateCrea.year();
        streamDateCrea >> chaineDateCrea;
        ui->DataListContact->setItem(0, 4, new QTableWidgetItem(QString::fromStdString(chaineDateCrea)));
     }

}

//ajouter un contact
void ListContact::on_addContact_clicked()
{
    ContactEntity* ce = new ContactEntity();
    //on passe false en parametre car on ajoute
    cf = new ContactForm(this, gestionnairecontact, gestionnaireinteraction, gestionnairetodo, ce, false);
    connect(cf, SIGNAL(signalEnregistrement()), this, SLOT(afficher_liste()));
    cf->show();

}

//voir un contact
void ListContact::on_seeContact_clicked()
{
    //on passe true en parametre car on modifie
    cf = new ContactForm(this, gestionnairecontact, gestionnaireinteraction, gestionnairetodo, gestionnairecontact->findContactById( ui->DataListContact->model()->index(ui->DataListContact->currentRow(),5).data().toInt()), true);
    connect(cf, SIGNAL(signalEnregistrement()), this, SLOT(afficher_liste()));
    cf->show();
}

//supprimer un contact
void ListContact::on_deleteContact_clicked()
{
    dcw = new DeleteContactWarning(this, gestionnairecontact->findContactById( ui->DataListContact->model()->index(ui->DataListContact->currentRow(),5).data().toInt()), gestionnairecontact);
    connect(dcw, SIGNAL(signalEnregistrement()), this, SLOT(afficher_liste()));
    dcw->show();
}

void ListContact::on_fitrerPb_clicked()
{
    string filtreNom = ui->filtreNomEdit->text().toStdString();

    string filtreEntreprise = ui->filtreEntrepriseEdit->text().toStdString();


    string filtreDateCrea="";

    if(ui->dateCreaCheckbox->isChecked()){
        stringstream streamDateCrea;
        streamDateCrea << ui->filtreDateCrea->date().day();
        streamDateCrea << "-";
        streamDateCrea <<  ui->filtreDateCrea->date().month();
        streamDateCrea << "-";
        streamDateCrea << ui->filtreDateCrea->date().year();
        streamDateCrea >> filtreDateCrea;
    }

    string filtreDateCreaMin="";

    string filtreDateCreaMax;

    if(ui->dateIntervalleCheckbox->isChecked()){
        stringstream streamDateCreaMin;
        streamDateCreaMin << ui->dateCreaMinEdit->date().day();
        streamDateCreaMin << "-";
        streamDateCreaMin <<  ui->dateCreaMinEdit->date().month();
        streamDateCreaMin << "-";
        streamDateCreaMin << ui->dateCreaMinEdit->date().year();
        streamDateCreaMin >> filtreDateCreaMin;

        stringstream streamDateCreaMax;
        streamDateCreaMax << ui->dateCreaMaxEdit->date().day();
        streamDateCreaMax << "-";
        streamDateCreaMax <<  ui->dateCreaMaxEdit->date().month();
        streamDateCreaMax << "-";
        streamDateCreaMax << ui->dateCreaMaxEdit->date().year();
        streamDateCreaMax >> filtreDateCreaMax;
    }


    afficher_liste(filtreNom, filtreEntreprise, filtreDateCrea, filtreDateCreaMin, filtreDateCreaMax);


}


void ListContact::on_effacerFiltrePb_clicked()
{
    afficher_liste();
}

void ListContact::on_dateIntervalleCheckbox_stateChanged(int arg1)
{
    if(arg1==0){
        ui->dateCreaMinEdit->setEnabled(false);
        ui->dateCreaMaxEdit->setEnabled(false);
    }else{
        ui->dateCreaMinEdit->setEnabled(true);
        ui->dateCreaMaxEdit->setEnabled(true);
    }
}


void ListContact::on_dateCreaCheckbox_stateChanged(int arg1)
{
    if(arg1==0){
        ui->filtreDateCrea->setEnabled(false);
    }else{
        ui->filtreDateCrea->setEnabled(true);
    }
}

