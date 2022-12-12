#ifndef DELETEINTERACTIONWARNING_H
#define DELETEINTERACTIONWARNING_H

#include "gestionnaireinteraction.h"
#include "interactionentity.h"
#include <QMainWindow>

namespace Ui {
class deleteinteractionwarning;
}

class deleteinteractionwarning : public QMainWindow
{
    Q_OBJECT

public:
    explicit deleteinteractionwarning(QWidget *parent = nullptr, InteractionEntity * interaction=nullptr, GestionnaireInteraction * gestionnaireInteraction=nullptr);
    ~deleteinteractionwarning();

private slots:
    void on_Yes_clicked();

    void on_No_clicked();

signals:

    void signalEnregistrement();

private:
    Ui::deleteinteractionwarning *ui;
    InteractionEntity * interaction;
    GestionnaireInteraction * gestionnaireInteraction;
};

#endif // DELETEINTERACTIONWARNING_H
