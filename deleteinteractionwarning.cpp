#include "deleteinteractionwarning.h"
#include "ui_deleteinteractionwarning.h"

deleteinteractionwarning::deleteinteractionwarning(QWidget *parent, InteractionEntity * interaction, GestionnaireInteraction * gestionnaireInteraction) :
    QMainWindow(parent),
    ui(new Ui::deleteinteractionwarning)
{
    ui->setupUi(this);

    this->interaction=interaction;
    this->gestionnaireInteraction=gestionnaireInteraction;
}

deleteinteractionwarning::~deleteinteractionwarning()
{
    delete ui;
}

void deleteinteractionwarning::on_Yes_clicked()
{
    gestionnaireInteraction->deleteInteraction(interaction);
    emit signalEnregistrement();
    this->close();
}


void deleteinteractionwarning::on_No_clicked()
{
    this->close();
}

