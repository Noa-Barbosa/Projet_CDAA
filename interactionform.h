#ifndef INTERACTIONFORM_H
#define INTERACTIONFORM_H

#include <QMainWindow>
#include <gestionnairecontact.h>
#include <gestionnaireinteraction.h>
#include <gestionnairetodo.h>

namespace Ui {
class InteractionForm;
}

class InteractionForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit InteractionForm(QWidget *parent = nullptr,GestionnaireContact* gestionnairecontact = nullptr, GestionnaireInteraction* gestionnaireinteraction = nullptr, GestionnaireTodo* gestionnairetodo = nullptr, ContactEntity * contactentity=nullptr,InteractionEntity* interactionEntity = nullptr, bool mod=false);
    ~InteractionForm();

signals:
    void signalEnregistrement();

private slots:
    void on_annulerPb_clicked();

    void on_enregisterPb_clicked();

private:
    Ui::InteractionForm *ui;
    GestionnaireContact * gestionnairecontact;
    GestionnaireInteraction* gestionnaireinteraction;
    GestionnaireTodo* gestionnairetodo;
    ContactEntity * contactentity;
    InteractionEntity* interactionentity;
    bool mod;
};

#endif // INTERACTIONFORM_H
