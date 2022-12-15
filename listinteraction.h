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

/**
 * @brief La page de liste des interactions
 */
class ListInteraction : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la page de liste
     * @param parent le parent de la page
     * @param gestionnairecontact le gestionnaire des contacts
     * @param gestionnaireinteraction le gestionnaire des interactions
     * @param gestionnairetodo le gestionnaire des todos
     * @param contactentity le contact dont on affiche les interactions
     */
    explicit ListInteraction(QWidget *parent = nullptr, GestionnaireContact* gestionnairecontact = nullptr, GestionnaireInteraction* gestionnaireinteraction = nullptr, GestionnaireTodo* gestionnairetodo = nullptr, ContactEntity* contactentity = nullptr);
    ~ListInteraction();

public slots:
    /**
     * @brief Affiche la liste des interactions
     */
    void afficher_liste_Interaction();

    /**
     * @brief Affiche la liste des todos
     */
    void afficher_liste_Todo();

private slots:

    /**
     * @brief Sur l'appuie du bouton ajouter interaction on ouvre une fenetre d'ajout
     */
    void on_addInteractionPb_clicked();

    /**
     * @brief Sur l'appuie du bouton modifier on ouvre une fenetre de modification
     */
    void on_modifierInteractionPb_clicked();

    /**
     * @brief Sur l'appuie du bouton supprimer on ouvre une fenetre de confirmation de suppression
     */
    void on_deleteInteractionPb_clicked();

private:

    /**
     * @brief Contenu de l'interface de la page
     */
    Ui::ListInteraction *ui;

    /**
     * @brief Le gestionnaire des contacts
     */
    GestionnaireContact * gestionnairecontact;

    /**
     * @brief Le gestionnaire des interactions
     */
    GestionnaireInteraction* gestionnaireinteraction;

    /**
     * @brief Le gestionnaire des todos
     */
    GestionnaireTodo* gestionnairetodo;

    /**
     * @brief Le contact dont on affiche les interactions
     */
    ContactEntity* contactentity;

    /**
     * @brief Pointeur vers la page d'ajout/modification d'une interaction
     */
    InteractionForm * interactionForm;

    /**
     * @brief Pointeur vers la page de confirmation de suppression d'un interaction
     */
    deleteinteractionwarning * diw;

};

#endif // LISTINTERACTION_H
