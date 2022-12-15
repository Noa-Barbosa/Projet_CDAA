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

/**
 * @brief Page de creation/modification d'un contact
 */
class ContactForm : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la page
     * @param parent le parent de la page
     * @param gestionnairecontact le gestionnaire des contacts
     * @param gestionnaireinteraction le gestionnaire des interactions
     * @param gestionnairetodo le gestionnaire des todos
     * @param contactentity le contact que l'on va ajouter ou modifier
     * @param mod le mode de la page vrai pour ajouter faux pour modifier
     */
    explicit ContactForm(QWidget *parent = nullptr, GestionnaireContact* gestionnairecontact = nullptr, GestionnaireInteraction* gestionnaireinteraction = nullptr, GestionnaireTodo* gestionnairetodo = nullptr, ContactEntity* contactentity = nullptr, bool mod=false);
    ~ContactForm();

private slots:

    /**
     * @brief Sur l'appui du bouton enregistrer on ajoute ou modifie le contact
     */
    void on_enregisterPb_clicked();

    /**
     * @brief Sur l'appui du bouton annuler on ferme la page et on ne fait rien
     */
    void on_annulerPb_clicked();

    /**
     * @brief Ouvre le selecteur de fichier pour choisir une photo
     */
    void on_changePhoto_clicked();

signals:

    /**
     * @brief Signal pour rafraichier l'affichage de la page principale
     */
    void signalEnregistrement();

private:

    /**
     * @brief Contenu de l'interface de la page
     */
    Ui::contactform *ui;

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
     * @brief Le contact que l'on va modifier/ajouter
     */
    ContactEntity* contactentity;

    /**
     * @brief Le mode de la page vrai si ajouter faux si modifier
     */
    bool mod;

};

#endif // CONTACTFORM_H
