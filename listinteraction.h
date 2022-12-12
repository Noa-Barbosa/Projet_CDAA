#ifndef LISTINTERACTION_H
#define LISTINTERACTION_H

#include "deleteinteractionwarning.h"
#include "interactionform.h"
#include <QMainWindow>
#include <gestionnairecontact.h>
#include <gestionnaireinteraction.h>
#include <gestionnairetodo.h>
#include <contactentity.h>

namespace Ui {
class ListInteraction;
}

class ListInteraction : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListInteraction(QWidget *parent = nullptr, GestionnaireContact* gestionnairecontact = nullptr, GestionnaireInteraction* gestionnaireinteraction = nullptr, GestionnaireTodo* gestionnairetodo = nullptr, ContactEntity* contactentity = nullptr);
    ~ListInteraction();

public slots:
    void afficher_liste_Interaction();

private slots:
    void on_deleteInteractionPb_clicked();

    void on_addInteractionPb_clicked();

private:
    Ui::ListInteraction *ui;
    GestionnaireContact * gestionnairecontact;
    GestionnaireInteraction* gestionnaireinteraction;
    GestionnaireTodo* gestionnairetodo;
    ContactEntity* contactentity;
    InteractionForm * interactionForm;
    deleteinteractionwarning * diw;

};

#endif // LISTINTERACTION_H
