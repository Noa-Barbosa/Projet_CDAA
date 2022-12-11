#ifndef LISTINTERACTION_H
#define LISTINTERACTION_H

#include <QMainWindow>

namespace Ui {
class ListInteraction;
}

class ListInteraction : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListInteraction(QWidget *parent = nullptr);
    ~ListInteraction();

private:
    Ui::ListInteraction *ui;
};

#endif // LISTINTERACTION_H
