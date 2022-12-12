#ifndef LISTINTERACTION_H
#define LISTINTERACTION_H

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

private:
    Ui::ListInteraction *ui;
    GestionnaireContact * gestionnairecontact;
    GestionnaireInteraction* gestionnaireinteraction;
    GestionnaireTodo* gestionnairetodo;
    ContactEntity* contactentity;
};

#endif // LISTINTERACTION_H
