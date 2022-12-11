#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <listcontact.h>
#include <listinteraction.h>
#include <gestionnairecontact.h>
#include <gestionnaireinteraction.h>
#include <gestionnairetodo.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, GestionnaireContact* gestionnairecontact = nullptr, GestionnaireInteraction* gestionnaireinteraction = nullptr, GestionnaireTodo* gestionnairetodo = nullptr);
    ~MainWindow();

private slots:
    void on_ListContact_clicked();

    void on_ListInteraction_clicked();

private:
    Ui::MainWindow *ui;
    ListContact *lc;
    ListInteraction *li;
    GestionnaireContact * gestionnairecontact;
    GestionnaireInteraction* gestionnaireinteraction;
    GestionnaireTodo* gestionnairetodo;

};
#endif // MAINWINDOW_H
