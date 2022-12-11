#ifndef LISTCONTACT_H
#define LISTCONTACT_H

#include <QMainWindow>
#include <gestionnaireBDD.h>
#include <gestionnairecontact.h>
#include <gestionnaireinteraction.h>
#include <gestionnairetodo.h>
#include <contactform.h>
#include <deletecontactwarning.h>


namespace Ui {
class ListContact;
}

class ListContact : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListContact(QWidget *parent = nullptr, GestionnaireContact* gestionnairecontact = nullptr, GestionnaireInteraction* gestionnaireinteraction = nullptr, GestionnaireTodo* gestionnairetodo = nullptr);
    ~ListContact();

public slots:
    void afficher_liste();

private slots:
    void on_addContact_clicked();

    void on_seeContact_clicked();

    void on_deleteContact_clicked();

    void on_Update_clicked();

private:
    Ui::ListContact *ui;
    GestionnaireContact * gestionnairecontact;
    GestionnaireInteraction* gestionnaireinteraction;
    GestionnaireTodo* gestionnairetodo;
    ContactForm* cf;
    DeleteContactWarning* dcw;

};

#endif // LISTCONTACT_H
