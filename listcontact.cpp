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

    afficher_liste();

}

ListContact::~ListContact()
{
    delete ui;
}

void ListContact::afficher_liste()
{
     ui->DataListContact->setRowCount(0);
     ui->DataListContact->setColumnHidden(4, true);
    //récupère les données
    list<ContactEntity *> lce;
    lce = gestionnairecontact->getContactList();
    //insére les données dans la table
    for(ContactEntity* ce : lce)
    {
        ui->DataListContact->insertRow(0);
        ui->DataListContact->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(ce->getNomContact())));
        ui->DataListContact->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(ce->getPrenomContact())));
        ui->DataListContact->setItem(0, 2, new QTableWidgetItem(QString::fromStdString(ce->getEntrepriseContact())));
        ui->DataListContact->setItem(0, 4, new QTableWidgetItem(QString::number(ce->getIdContact())));
        //string pour les dates
        year_month_day dateCrea = ce->getDateCreaContact();
        stringstream streamDateCrea;
        string chaineDateCrea;
        streamDateCrea << dateCrea;
        streamDateCrea >> chaineDateCrea;
        ui->DataListContact->setItem(0, 3, new QTableWidgetItem(QString::fromStdString(chaineDateCrea)));
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
    cf = new ContactForm(this, gestionnairecontact, gestionnaireinteraction, gestionnairetodo, gestionnairecontact->findContactById( ui->DataListContact->model()->index(ui->DataListContact->currentRow(),4).data().toInt()), true);
    connect(cf, SIGNAL(signalEnregistrement()), this, SLOT(afficher_liste()));
    cf->show();
}

//supprimer un contact
void ListContact::on_deleteContact_clicked()
{
    dcw = new DeleteContactWarning(this, gestionnairecontact->findContactById( ui->DataListContact->model()->index(ui->DataListContact->currentRow(),4).data().toInt()), gestionnairecontact);
    connect(dcw, SIGNAL(signalEnregistrement()), this, SLOT(afficher_liste()));
    dcw->show();
}

void ListContact::on_Update_clicked()
{
    afficher_liste();
}

