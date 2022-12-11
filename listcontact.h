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
    /**
     * @brief Affiche la liste des contact filtrer s'il des filtre son preciser
     * @param filtreNom le nom recherche
     * @param filtreEntreprise l'entreprise recherchee
     * @param filtreDateCrea la date de creation recherchee
     */
    void afficher_liste(string filtreNom ="", string filtreEntreprise="", string filtreDateCrea="", string filtreDateCreaMin="", string filtreDateCreaMax="");

private slots:
    void on_addContact_clicked();

    void on_seeContact_clicked();

    void on_deleteContact_clicked();

    void on_fitrerPb_clicked();

    void on_effacerFiltrePb_clicked();

    void on_dateIntervalleCheckbox_stateChanged(int arg1);

    void on_dateCreaCheckbox_stateChanged(int arg1);

private:
    Ui::ListContact *ui;
    GestionnaireContact * gestionnairecontact;
    GestionnaireInteraction* gestionnaireinteraction;
    GestionnaireTodo* gestionnairetodo;
    ContactForm* cf;
    DeleteContactWarning* dcw;

};

#endif // LISTCONTACT_H
