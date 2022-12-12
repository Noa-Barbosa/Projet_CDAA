#include "interactionform.h"
#include "qmessagebox.h"
#include "ui_interactionform.h"
#include <algorithm>

InteractionForm::InteractionForm(QWidget *parent, GestionnaireContact * gestionnaireContact, GestionnaireInteraction * gestionnaireInteraction, GestionnaireTodo * gestionnaireTodo, ContactEntity * contactentity, InteractionEntity* interactionEntity, bool mod) :
    QMainWindow(parent),
    ui(new Ui::InteractionForm)
{
    ui->setupUi(this);
    this->gestionnairecontact=gestionnaireContact;
    this->gestionnaireinteraction=gestionnaireInteraction;
    this->gestionnairetodo=gestionnaireTodo;
    this->contactentity=contactentity;
    this->interactionentity=interactionEntity;
    this->mod=mod;
    ui->contenuEdit->setText(QString::fromStdString(interactionentity->getContenuInteraction()));

    year_month_day dateCrea = interactionEntity->getDateAjoutInteraction();
    stringstream streamDateCrea;
    string chaineDateCrea;
    streamDateCrea << dateCrea;
    streamDateCrea >> chaineDateCrea;
    ui->dateLabel->setText(QString::fromStdString(chaineDateCrea));
}

InteractionForm::~InteractionForm()
{
    delete ui;
}

void InteractionForm::on_enregisterPb_clicked()
{
    InteractionEntity * interaction = new InteractionEntity();
    string contenu =ui->contenuEdit->text().toStdString();

    interaction->setContenuInteraction(contenu);

    QMessageBox messageBox;
    if(contenu.empty()){
        messageBox.information(this, "Champ invalide","Le champ contenu ne doit pas être vide");
        messageBox.setFixedSize(500,200);
    }
    else{
        gestionnaireinteraction->addInteraction(interaction,contactentity);

        //on enleve les espaces pour faciliter le traitement
        std::string::iterator end_pos = std::remove(contenu.begin(), contenu.end(), ' ');
        contenu.erase(end_pos, contenu.end());

        auto posTodo = contenu.find("@todo");
        auto posDate = contenu.find("@date");

        string contenuTodo;
        //si on a bien un todo dans le contenu
        if(posTodo!= string::npos){
            TodoEntity * todo= new TodoEntity();
            //si on a pas de @date dans le contenu on veut aller jusqu'à la fin de la chaine
            if(posDate==string::npos){
                posDate=contenu.size();
            }
            for (unsigned long long i = posTodo+5; i < posDate; i++) {
              contenuTodo+=contenu.at(i);
            }

            todo->setContenuTodo(contenuTodo);

            string dateTodo;

            posDate = contenu.find("@date");
            //si on a une @date dans le contenu
            if(posDate!=string::npos){
                for (unsigned long long i = posDate+5; i < contenu.size(); i++) {
                  dateTodo+=contenu.at(i);
                }

                std::vector<std::string> partiesDate;
                std::string partie;
                std::istringstream dateStream(dateTodo);
                while (std::getline(dateStream, partie, '-'))
                {
                   partiesDate.push_back(partie);
                }

                int jour = std::stoi(partiesDate.at(0));
                int mois = std::stoi(partiesDate.at(1));
                int annee = std::stoi(partiesDate.at(2));

                year_month_day dateCreaTodo =year{annee}/mois/jour;

                todo->setDateAjoutTodo(dateCreaTodo);
            }

            gestionnairetodo->addTodo(todo,gestionnaireinteraction->findInteraction(interaction));

        }
        emit signalEnregistrement();
    }


}

void InteractionForm::on_annulerPb_clicked()
{
    this->close();
}
