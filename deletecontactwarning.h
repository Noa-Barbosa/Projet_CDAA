#ifndef DELETECONTACTWARNING_H
#define DELETECONTACTWARNING_H

#include <QMainWindow>
#include <contactentity.h>
#include <gestionnairecontact.h>

namespace Ui {
class DeleteContactWarning;
}

class DeleteContactWarning : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteContactWarning(QWidget *parent = nullptr, ContactEntity* contact = nullptr, GestionnaireContact* gestionnairecontact = nullptr);
    ~DeleteContactWarning();

private slots:
    void on_Yes_clicked();

    void on_No_clicked();

signals:
    void signalEnregistrement();

private:
    Ui::DeleteContactWarning *ui;
    ContactEntity* contact;
    GestionnaireContact* gestionnairecontact;
};

#endif // DELETECONTACTWARNING_H
