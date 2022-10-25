#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <interactionentity.h>
#include <contactentity.h>

int main(int argc, char *argv[])
{
    //test de creation d'un contact avec le constructeur vide et les mutateur et test de l'affichage
    std::cout << "test de creation d'un contact avec le constructeur vide et les mutateur et test de l'affichage" << std::endl;
    ContactEntity Contact1;
    Contact1.setNomContact("Barbosa test mutateur contact");
    Contact1.setPrenomContact("Noa");
    Contact1.setEntrepriseContact("McDonald's");
    Contact1.setMailContact("noa.barbosa@hotmail.Fr");
    list<unsigned> numTelContact1 = {0,1,2,5,4,8,9,5,1,0};
    Contact1.setTelContact(numTelContact1);
    Contact1.setPhotoContact("Projet/ProjetQT/photo_contact1.jpg");
    std::cout << Contact1 << std::endl<<std::endl;

    //test de creation d'un contact avec le constructeur avec parametres et affichage
    std::cout << "test de creation d'un contact avec le constructeur avec parametres et affichage" << std::endl;
    list<unsigned> numTelContact2 = {8,7,2,5,9,8,9,4,1,0};
    ContactEntity Contact2("Boisson test constructeur contact","Adrien","Sylph Sarl","exemple@1outlook.fr",numTelContact2,"Projet/ProjetQT/photo_contact2.jpg");
    std::cout << Contact2 << std::endl<<std::endl;

    //test de creation d'une interaction avec le constructeur vide et un mutateur et test de l'affichage
    InteractionEntity Interaction1;
    std::cout << "test de creation d'une interaction avec le constructeur vide et un mutateur et test de l'affichage" << std::endl;
    Interaction1.setContenuInteraction("Contenu interaction 1");
    std::cout<<Interaction1<<std::endl<<std::endl;

    //test de creation d'une interaction avec le constructeur avec parametre et affichage
    std::cout << "test de creation d'une interaction avec le constructeur avec parametre et affichage" << std::endl;
    InteractionEntity Interaction2("Contenu interaction 2");
    std::cout << Interaction2 << std::endl<<std::endl ;


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
