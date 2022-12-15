#ifndef DELETECONTACTWARNING_H
#define DELETECONTACTWARNING_H

#include <QMainWindow>
#include <contactentity.h>
#include <gestionnairecontact.h>

namespace Ui {
class DeleteContactWarning;
}

/**
 * @brief Page de confirmation de suppression d'un contact
 */
class DeleteContactWarning : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la page
     * @param parent pointeur sur le widget parent de la page
     * @param contact pointeur le contact qui va etre supprime
     * @param gestionnairecontact pointeur sur le gestionnaire de contact
     */
    explicit DeleteContactWarning(QWidget *parent = nullptr, ContactEntity* contact = nullptr, GestionnaireContact* gestionnairecontact = nullptr);

    ~DeleteContactWarning();

private slots:
    /**
     * @brief Sur l'appuie du bouton oui on supprime le contact
     */
    void on_Yes_clicked();

    /**
     * @brief Sur l'appuie du bouton non on ferme la page sans rien faire
     */
    void on_No_clicked();

signals:
    /**
     * @brief Signal pour actualiser l'affichage de la page principale
     */
    void signalEnregistrement();

private:
    /**
     * @brief Contient toute l'interface de la page
     */
    Ui::DeleteContactWarning *ui;

    /**
     * @brief Le contact qui va etre supprimer
     */
    ContactEntity* contact;

    /**
     * @brief le gestionnaire de contact pour supprimer
     */
    GestionnaireContact* gestionnairecontact;
};

#endif // DELETECONTACTWARNING_H
