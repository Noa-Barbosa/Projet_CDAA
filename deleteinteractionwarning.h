#ifndef DELETEINTERACTIONWARNING_H
#define DELETEINTERACTIONWARNING_H

#include "gestionnaireinteraction.h"
#include "interactionentity.h"
#include <QMainWindow>

namespace Ui {
class deleteinteractionwarning;
}

/**
 * @brief Page de confirmation de suppression d'une interaction
 */
class deleteinteractionwarning : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la page
     * @param parent le parent de la page
     * @param interaction l'interaction a supprimee
     * @param gestionnaireInteraction le gestionnaire d'interaction qui va supprimer
     */
    explicit deleteinteractionwarning(QWidget *parent = nullptr, InteractionEntity * interaction=nullptr, GestionnaireInteraction * gestionnaireInteraction=nullptr);
    ~deleteinteractionwarning();

private slots:
    /**
     * @brief Si on appuie sur oui on supprime l'interaction
     */
    void on_Yes_clicked();

    /**
     * @brief Si on appuie sur non ça ferme la page sans rien faire
     */
    void on_No_clicked();

signals:

    /**
     * @brief Signal envoye pour actualiser l'affichage des contacts
     */
    void signalEnregistrement();

private:
    /**
     * @brief Contient toutes l'interface de la page
     */
    Ui::deleteinteractionwarning *ui;

    /**
     * @brief L'interaction a supprime
     */
    InteractionEntity * interaction;

    /**
     * @brief Le gestionnaire d'interaction qui va supprimer
     */
    GestionnaireInteraction * gestionnaireInteraction;
};

#endif // DELETEINTERACTIONWARNING_H
