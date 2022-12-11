#include "listinteraction.h"
#include "ui_listinteraction.h"

ListInteraction::ListInteraction(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ListInteraction)
{
    ui->setupUi(this);
}

ListInteraction::~ListInteraction()
{
    delete ui;
}
