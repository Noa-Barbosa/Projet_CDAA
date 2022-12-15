#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listcontact.h"

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

    lc = new ListContact(this, gestionnairecontact, gestionnaireinteraction, gestionnairetodo);
    lc->show();


}

