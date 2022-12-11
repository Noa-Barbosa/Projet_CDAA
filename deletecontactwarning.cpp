#include "deletecontactwarning.h"
#include "ui_deletecontactwarning.h"

DeleteContactWarning::DeleteContactWarning(QWidget *parent, ContactEntity* contact, GestionnaireContact* gestionnairecontact) :
    QMainWindow(parent),
    ui(new Ui::DeleteContactWarning)
{
    ui->setupUi(this);
    this->contact = contact;
    this->gestionnairecontact = gestionnairecontact;
}

DeleteContactWarning::~DeleteContactWarning()
{
    delete ui;
}

void DeleteContactWarning::on_Yes_clicked()
{
    gestionnairecontact->deleteContact(contact);
    this->close();
}


void DeleteContactWarning::on_No_clicked()
{
    this->close();
}

