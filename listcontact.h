#ifndef LISTCONTACT_H
#define LISTCONTACT_H

#include "qmessagebox.h"
#include <QMainWindow>
#include <gestionnaireBDD.h>
#include <gestionnairecontact.h>
#include <gestionnaireinteraction.h>
#include <gestionnairetodo.h>
#include <contactform.h>
#include <deletecontactwarning.h>
#include <listinteraction.h>


namespace Ui {
class ListContact;
}

/**
 * @brief Page de liste des contacts
 */
class ListContact : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la page
     * @param parent le parent de la page
     * @param gestionnairecontact le gestionnaire des contacts
     * @param gestionnaireinteraction le gestionnaire des interactions
     * @param gestionnairetodo le gestionnaire des todos
     */
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
    /**
     * @brief Sur l'appuie du bouton ajout on ouvre un contactForm en mode ajout
     */
    void on_addContact_clicked();

    /**
     * @brief Sur l'appui du bouton modification on ouvre un contactform en mode modification
     */
    void on_seeContact_clicked();

    /**
     * @brief Sur l'appui du bouton supprimer on ouvre la fenetre de confirmation
     */
    void on_deleteContact_clicked();

    /**
     * @brief Sur l'appuie du bouton filtrer on affiche la liste avec les bons filtres
     */
    void on_fitrerPb_clicked();

    /**
     * @brief Sur l'appui du bouton effacer on affiche la liste sans filtrage et on efface les filtres
     */
    void on_effacerFiltrePb_clicked();

    /**
     * @brief Au changement d'etat de la checkbox on active ou desactive les datepickers
     * @param arg1 l'etat de la checkbox
     */
    void on_dateIntervalleCheckbox_stateChanged(int arg1);

    /**
     * @brief Au changement d'etat de la checkbox on active ou desactive le datepicker
     * @param arg1 l'etat de la checkbox
     */
    void on_dateCreaCheckbox_stateChanged(int arg1);

    /**
     * @brief Sur l'appuie du bouton voir interaction on affiche la liste des interactions et des todos du contact
     */
    void on_interactionsContact_clicked();

    /**
     * @brief Quand on clique sur le menu ajouter un contact on ouvre la fenetre d'ajout du contact
     */
    void on_actionAjouter_un_contact_triggered();

private:
    /**
     * @brief Contient l'interface de la page
     */
    Ui::ListContact *ui;

    /**
     * @brief Le gestionnaire des contacts
     */
    GestionnaireContact * gestionnairecontact;

    /**
     * @brief Le gestionnnaire des interactions
     */
    GestionnaireInteraction* gestionnaireinteraction;

    /**
     * @brief Le gestionnaire des todos
     */
    GestionnaireTodo* gestionnairetodo;

    /**
     * @brief pointeur vers une page d'ajout de contact
     */
    ContactForm* cf;

    /**
     * @brief pointeur vers une page de confirmation de suppression d'un contact
     */
    DeleteContactWarning* dcw;

    /**
     * @brief pointeur vers une page de liste des interaction
     */
    ListInteraction* li;

    /**
     * @brief pointeur sur la qmessagebox pour prevenir l'utilisateur quand la recherche ne donne rien
     */
    QMessageBox * messageRecherche;

};

#endif // LISTCONTACT_H
