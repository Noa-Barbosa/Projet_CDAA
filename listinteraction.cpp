#include "listinteraction.h"
#include "ui_listinteraction.h"

ListInteraction::ListInteraction(QWidget *parent, GestionnaireContact* gestionnairecontact, GestionnaireInteraction* gestionnaireinteraction, GestionnaireTodo* gestionnairetodo, ContactEntity* contactentity) :
    QMainWindow(parent),
    ui(new Ui::ListInteraction)
{
    ui->setupUi(this);
    this->gestionnairecontact = gestionnairecontact;
    this->gestionnaireinteraction = gestionnaireinteraction;
    this->gestionnairetodo = gestionnairetodo;
    this->contactentity = contactentity;
    afficher_liste_Interaction();
}

ListInteraction::~ListInteraction()
{
    delete ui;
}

void ListInteraction::afficher_liste_Interaction()
{
     ui->DataListInteraction->setRowCount(0);
     ui->DataListInteraction->setColumnHidden(2, true);
    //récupère les données
    list<InteractionEntity *> listEntity;

    listEntity = gestionnairecontact->listAllInteractions(contactentity);
    //insére les données dans la table
    for(InteractionEntity* ie : listEntity)
    {
        ui->DataListInteraction->insertRow(0);
        ui->DataListInteraction->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(ie->getContenuInteraction())));
        //les dates
        year_month_day dateCrea = ie->getDateAjoutInteraction();

        stringstream streamDateCrea;
        string chaineDateCrea;
        streamDateCrea << dateCrea.day();
        streamDateCrea << "-";
        streamDateCrea << dateCrea.month();
        streamDateCrea << "-";
        streamDateCrea << dateCrea.year();
        streamDateCrea >> chaineDateCrea;
        ui->DataListInteraction->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(chaineDateCrea)));
        ui->DataListInteraction->setItem(0, 2, new QTableWidgetItem(QString::number(ie->getIdInteraction())));
     }


}

void ListInteraction::on_deleteInteractionPb_clicked()
{
    diw = new deleteinteractionwarning(this, gestionnaireinteraction->findInteractionById(ui->DataListInteraction->model()->index(ui->DataListInteraction->currentRow(),2).data().toInt()), gestionnaireinteraction);
    connect(diw, SIGNAL(signalEnregistrement()), this, SLOT(afficher_liste_Interaction()));
    diw->show();
}

