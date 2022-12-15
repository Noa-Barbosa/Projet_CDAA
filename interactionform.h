#ifndef INTERACTIONFORM_H
#define INTERACTIONFORM_H

#include <QMainWindow>
#include <gestionnairecontact.h>
#include <gestionnaireinteraction.h>
#include <gestionnairetodo.h>

namespace Ui {
class InteractionForm;
}

/**
 * @brief Page de creation d'une interaction
 */
class InteractionForm : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe
     * @param parent le parent de la page
     * @param gestionnairecontact le gestionnaire des contacts
     * @param gestionnaireinteraction le gestionnaire des interactions
     * @param gestionnairetodo le gestionnaire des todos
     * @param contactentity le contact auquel on va ajouter une interaction
     * @param interactionEntity l'interaction a ajoute
     * @param mod le mode de la page soit vrai pour ajouter faux pour modifier
     */
    explicit InteractionForm(QWidget *parent = nullptr,GestionnaireContact* gestionnairecontact = nullptr, GestionnaireInteraction* gestionnaireinteraction = nullptr, GestionnaireTodo* gestionnairetodo = nullptr, ContactEntity * contactentity=nullptr,InteractionEntity* interactionEntity = nullptr, bool mod=false);
    ~InteractionForm();

signals:
    /**
     * @brief Le signal d'enregistrement envoye a la page principale pour rafraichir sa liste
     */
    void signalEnregistrement();

private slots:

    /**
     * @brief Enregistre l'interaction en base a l'appui sur enregistrer
     */
    void on_enregisterPb_clicked();

    /**
     * @brief Ferme la fenetre et ne fait rien
     */
    void on_annulerPb_clicked();

private:
    /**
     * @brief Contient l'interface de la page
     */
    Ui::InteractionForm *ui;

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
     * @brief Le contact auquel on ajoute une interaction
     */
    ContactEntity * contactentity;

    /**
     * @brief L'interaction a ajoutee
     */
    InteractionEntity* interactionentity;

    /**
     * @brief Le mode de la page vrai pour ajouter faux pour modifier
     */
    bool mod;
};

#endif // INTERACTIONFORM_H
