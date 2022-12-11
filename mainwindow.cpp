#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listcontact.h"
#include "listinteraction.h"

MainWindow::MainWindow(QWidget *parent, GestionnaireContact* gestionnairecontact, GestionnaireInteraction* gestionnaireinteraction, GestionnaireTodo* gestionnairetodo)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->gestionnairecontact = gestionnairecontact;
    this->gestionnaireinteraction = gestionnaireinteraction;
    this->gestionnairetodo = gestionnairetodo;

}

MainWindow::~MainWindow()
{
    delete ui;
}

//voir la liste des contacts
void MainWindow::on_ListContact_clicked()
{
    hide();
    lc = new ListContact(this, gestionnairecontact, gestionnaireinteraction, gestionnairetodo);
    lc->show();

}

//voir la liste des intéractions
void MainWindow::on_ListInteraction_clicked()
{
    hide();
    li = new ListInteraction;
    li->show();
}

