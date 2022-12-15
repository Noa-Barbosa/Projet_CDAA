#ifndef CONTACTFORM_H
#define CONTACTFORM_H

#include <QMainWindow>
#include <gestionnaireBDD.h>
#include <gestionnairecontact.h>
#include <gestionnaireinteraction.h>
#include <gestionnairetodo.h>
#include <contactentity.h>
#include <QFileDialog>

namespace Ui {
class contactform;
}

class ContactForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit ContactForm(QWidget *parent = nullptr, GestionnaireContact* gestionnairecontact = nullptr, GestionnaireInteraction* gestionnaireinteraction = nullptr, GestionnaireTodo* gestionnairetodo = nullptr, ContactEntity* contactentity = nullptr, bool mod=false);
    ~ContactForm();

private slots:
    void on_enregisterPb_clicked();

    void on_annulerPb_clicked();

    void on_changePhoto_clicked();

signals:

    void signalEnregistrement();

private:
    Ui::contactform *ui;
    GestionnaireContact * gestionnairecontact;
    GestionnaireInteraction* gestionnaireinteraction;
    GestionnaireTodo* gestionnairetodo;
    ContactEntity* contactentity;
    bool mod;

};

#endif // CONTACTFORM_H
