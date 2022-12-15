#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <listcontact.h>
#include <gestionnairecontact.h>
#include <gestionnaireinteraction.h>
#include <gestionnairetodo.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Page d'accueil de l'application
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur
     * @param parent le parent de la page
     * @param gestionnairecontact le gestionnaire de contact
     * @param gestionnaireinteraction le gestionnaire d'interaction
     * @param gestionnairetodo le gestionnaire de todo
     */
    MainWindow(QWidget *parent = nullptr, GestionnaireContact* gestionnairecontact = nullptr, GestionnaireInteraction* gestionnaireinteraction = nullptr, GestionnaireTodo* gestionnairetodo = nullptr);
    ~MainWindow();

private slots:

    /**
     * @brief Sur l'appuie du bouton liste des contacts on affiche la page de liste des contacts
     */
    void on_ListContact_clicked();

private:

    /**
     * @brief Contenu de l'interface de la page
     */
    Ui::MainWindow *ui;

    /**
     * @brief Pointeur vers la page de liste des contacts
     */
    ListContact *lc;

    /**
     * @brief le gestionnaire des contacts
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

};
#endif // MAINWINDOW_H
