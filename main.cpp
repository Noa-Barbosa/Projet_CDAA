#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <interactionentity.h>
#include <contactentity.h>
#include <todoentity.h>
#include <contactinteractionentity.h>
#include <interactiontodoentity.h>
#include <gestionnaireBDD.h>
#include <gestionnaireinteraction.h>
#include <gestionnairetodo.h>
#include <gestionnairecontact.h>

#define _STR(x) #x
#define STR(x)  _STR(x)

int main(int argc, char *argv[])
{
    const QString project_path = STR(PROJECT_PATH);
    const QString database_path = project_path+"/database/CRM.db";

    GestionnaireBDD *gestionnaireBDD = new GestionnaireBDD(database_path);
    GestionnaireContact* gestionnaireContact = new GestionnaireContact(gestionnaireBDD);
    GestionnaireInteraction* gestionnaireInteraction = new GestionnaireInteraction(gestionnaireBDD);
    GestionnaireTodo* gestionnaireTodo = new GestionnaireTodo(gestionnaireBDD);


    //Test de recuperation des listes
    auto listContact = gestionnaireContact->getContactList();
    auto listInteraction = gestionnaireInteraction->getInteractionList();
    auto listContactInteraction = gestionnaireContact->getContactInteractionList();
    auto listTodo = gestionnaireTodo->getTodoList();
    auto listInteractionTodo = gestionnaireInteraction->getInteractionTodoList();

    /**
    gestionnaireBDD->beginTransaction();

    //Test ajout d'un contact
    ContactEntity *contact = new ContactEntity();
    contact->setNomContact("Test");
    contact->setPrenomContact("ajout contact");
    contact->setEntrepriseContact("Microsoft");
    contact->setMailContact("ok.daccord@gmail.com");
    list<unsigned> numTelContact1 = {4,1,2,5,4,8,5,5,9,0};
    contact->setTelContact(numTelContact1);
    contact->setPhotoContact("Projet/ProjetQT/photo_contact1.jpg");
    gestionnaireContact->addContact(contact);
    //on recherche le contact dans la liste pour avoir son identifiant
    contact = gestionnaireContact->findContactByMail("ok.daccord@gmail.com");

    listContact = gestionnaireContact->getContactList();

    //Test ajout d'un interaction
    InteractionEntity * interaction = new InteractionEntity();
    interaction->setContenuInteraction("Test ajout interaction");
    gestionnaireInteraction->addInteraction(interaction, contact);

    interaction = gestionnaireInteraction->findInteraction(interaction);
    listInteraction = gestionnaireInteraction->getInteractionList();
    listContactInteraction = gestionnaireContact->getContactInteractionList();

    //Test ajout d'un todo
    TodoEntity * todo = new TodoEntity();
    todo->setContenuTodo("Test ajout todo");
    gestionnaireTodo->addTodo(todo, interaction);
    todo = gestionnaireTodo->findTodo(todo);

    listTodo = gestionnaireTodo->getTodoList();
    listInteractionTodo = gestionnaireInteraction->getInteractionTodoList();

    //Test edition d'une interaction, d'un contact et d'un todo
    ContactEntity * editContact = new ContactEntity(contact);
    editContact->setNomContact("Test edition contact");
    gestionnaireContact->editContact(contact, editContact);
    InteractionEntity * editInteraction = new InteractionEntity();
    editInteraction->setContenuInteraction("Test edition interaction");
    gestionnaireInteraction->editInteraction(interaction, editInteraction);
    TodoEntity * editTodo = new TodoEntity();
    editTodo->setContenuTodo("Test edition todo");
    gestionnaireTodo->editTodo(todo,editTodo);

    listContact = gestionnaireContact->getContactList();
    listInteraction = gestionnaireInteraction->getInteractionList();
    listTodo = gestionnaireTodo->getTodoList();
    listContactInteraction = gestionnaireContact->getContactInteractionList();
    listInteractionTodo = gestionnaireInteraction->getInteractionTodoList();

    //Test delete todo
    gestionnaireTodo->deleteTodo(todo);

    listTodo = gestionnaireTodo->getTodoList();
    listInteractionTodo = gestionnaireInteraction->getInteractionTodoList();

    //Test delete interaction
    gestionnaireInteraction->deleteInteraction(interaction);

    listInteraction = gestionnaireInteraction->getInteractionList();
    listContactInteraction = gestionnaireContact->getContactInteractionList();
    listTodo = gestionnaireTodo->getTodoList();
    listInteractionTodo = gestionnaireInteraction->getInteractionTodoList();

    //Test delete contact
    contact = gestionnaireContact->findContactByMail("azdazdazd");
    gestionnaireContact->deleteContact(contact);

    listContact = gestionnaireContact->getContactList();
    listInteraction = gestionnaireInteraction->getInteractionList();
    listTodo = gestionnaireTodo->getTodoList();
    listContactInteraction = gestionnaireContact->getContactInteractionList();
    listInteractionTodo = gestionnaireInteraction->getInteractionTodoList();

    gestionnaireBDD->rollbackTransaction();
    **/

    /**
    //test de creation d'un contact avec le constructeur vide et les mutateur et test de l'affichage
    std::cout << "test de creation d'un contact avec le constructeur vide et les mutateur et test de l'affichage" << std::endl;
    ContactEntity *Contact1 = new ContactEntity();
    Contact1->setNomContact("Barbosa test mutateur contact");
    Contact1->setPrenomContact("Noa");
    Contact1->setEntrepriseContact("McDonald's");
    Contact1->setMailContact("noa.barbosa@hotmail.Fr");
    list<unsigned> numTelContact1 = {0,1,2,5,4,8,9,5,1,0};
    Contact1->setTelContact(numTelContact1);
    Contact1->setPhotoContact("Projet/ProjetQT/photo_contact1.jpg");
    std::cout << *Contact1 << std::endl<<std::endl;
    gestionnaireContact.addContact(Contact1);

    //test de creation d'un contact avec le constructeur avec parametres et affichage
    std::cout << "test de creation d'un contact avec le constructeur avec parametres et affichage" << std::endl;
    list<unsigned> numTelContact2 = {8,7,2,5,9,8,9,4,1,0};
    ContactEntity* Contact2 = new ContactEntity("Boisson test constructeur contact","Adrien","Sylph Sarl","exemple@1outlook.fr",numTelContact2,"Projet/ProjetQT/photo_contact2.jpg");
    std::cout << *Contact2 << std::endl<<std::endl;
    gestionnaireContact.addContact(Contact2);

    //test de creation d'une interaction avec le constructeur vide et un mutateur et test de l'affichage
    InteractionEntity *Interaction1 = new InteractionEntity("Contenu 1");
    std::cout << "test de creation d'une interaction avec le constructeur vide et un mutateur et test de l'affichage" << std::endl;
    Interaction1->setContenuInteraction("Contenu interaction 1");
    std::cout<<*Interaction1<<std::endl<<std::endl;
    //ajout de l'interaction dans la liste
    gestionnaireInteraction.addInteraction(Interaction1,Contact1);

    //test de creation d'une interaction avec le constructeur avec parametre et affichage
    std::cout << "test de creation d'une interaction avec le constructeur avec parametre et affichage" << std::endl;
    InteractionEntity* Interaction2 = new InteractionEntity("Contenu 2");
    std::cout << *Interaction2 << std::endl<<std::endl ;
    //ajout de l'interaction dans la liste
    gestionnaireInteraction.addInteraction(Interaction2,Contact1);

    std::cout << "test de creation d'un todo avec constructeur vide et mutateur" << endl;
    TodoEntity* Todo1 = new TodoEntity();
    Todo1->setContenuTodo("@todo test constructeur vide et mutateur");
    std::cout << *Todo1 << std::endl<<std::endl ;
    //ajout du todo dans la liste
    gestionnaireTodo.addTodo(Todo1,Interaction1);

    std::cout << "test de creation d'un todo avec constructeur parametrique" << std::endl;
    TodoEntity* Todo2 = new TodoEntity("@todo test constructeur parametrique");
    std::cout << *Todo2 << std::endl<<std::endl ;
    //ajout du todo a la liste
    gestionnaireTodo.addTodo(Todo2,Interaction1);

    std::cout << "test de creation, de modification, et de suppression des contact des interactions  et des todo avec les gestionnaires" << std::endl;
    ContactEntity *Contact3 = new ContactEntity();

    ContactEntity *Contact4 = new ContactEntity();

    gestionnaireContact.addContact(Contact3);

    gestionnaireContact.editContact(Contact3, Contact2);

    gestionnaireContact.deleteContact(Contact4);

    InteractionEntity* Interaction3 = new InteractionEntity("Contenu 3 edit");

    gestionnaireInteraction.editInteraction(Interaction2, Interaction3);

    gestionnaireInteraction.deleteInteraction(Interaction2);

    TodoEntity* Todo3 = new TodoEntity("@todo EDIT");

    gestionnaireTodo.editTodo(Todo2,Todo3);

    gestionnaireTodo.deleteTodo(Todo2);

    //tests des fonctions find
    std::cout << "test des fonctions find" << std::endl;
    std::cout << "test de la fonction findContactByNom" << std::endl;
    ContactEntity *contactRecherche1 = gestionnaireContact.findContactByNom("Boisson test constructeur contact");
    if(contactRecherche1==Contact2)
    {
        std::cout << "Nous avons trouvé le bon contact par nom" << std::endl;
    }
    else
    {
       std::cout << "Nous n'avons pas trouvé de contact par nom" << std::endl;
    }

    if(contactRecherche1==Contact3)
    {
        std::cout << "Nous avons trouvé le bon contact par nom" << std::endl;
    }
    else
    {
       std::cout << "Nous n'avons pas trouvé de contact par nom" << std::endl;
    }

    std::cout << std::endl << "test de la fonction findByEntreprise" << std::endl;
    contactRecherche1 = gestionnaireContact.findByEntreprise("Sylph");

    if(contactRecherche1==Contact2)
    {
        std::cout << "Nous avons trouvé le bon contact par entreprise" << std::endl;
    }
    else
    {
       std::cout << "Nous n'avons pas trouvé de contact par entreprise" << std::endl;
    }

    contactRecherche1 = gestionnaireContact.findByEntreprise("Sylph Sarl");

    if(contactRecherche1==Contact2)
    {
        std::cout << "Nous avons trouvé le bon contact par entreprise" << std::endl;
    }
    else
    {
       std::cout << "Nous n'avons pas trouvé de contact par entreprise" << std::endl;
    }

    std::cout << std::endl << "test de la fonction findByDateCrea" << std::endl;
    contactRecherche1 = gestionnaireContact.findByDateCrea(Contact2->getDateCreaContact());

    if(contactRecherche1==Contact2)
    {
        std::cout << "Nous avons trouvé le bon contact par la date de création" << std::endl;
    }
    else
    {
       std::cout << "Nous n'avons pas trouvé de contact par la date de création" << std::endl;
    }

    if(contactRecherche1==Contact3)
    {
        std::cout << "Nous avons trouvé le bon contact par la date de création" << std::endl;
    }
    else
    {
       std::cout << "Nous n'avons pas trouvé de contact par la date de création" << std::endl;
    }

    std::cout << std::endl << "test de la fonction findByDateModif" << std::endl;
    contactRecherche1 = gestionnaireContact.findByDateModif(Contact3->getDateLastUpdate());

    if(contactRecherche1==Contact2)
    {
        std::cout << "Nous avons trouvé le bon contact par la date de modification" << std::endl;
    }
    else
    {
       std::cout << "Nous n'avons pas trouvé de contact par la date de modification" << std::endl;
    }

    if(contactRecherche1==Contact3)
    {
        std::cout << "Nous avons trouvé le bon contact par la date de modification" << std::endl;
    }
    else
    {
       std::cout << "Nous n'avons pas trouvé de contact par la date de modification" << std::endl;
    }

    std::cout << std::endl << "test de la fonction findByDateCreaBetween" << std::endl;
    contactRecherche1 = gestionnaireContact.findByDateCreaBetween(Contact1->getDateCreaContact(), Contact3->getDateCreaContact());

    if(contactRecherche1==Contact1)
    {
        std::cout << "Nous avons trouvé le bon contact par la date de création" << std::endl;
    }
    else
    {
       std::cout << "Nous n'avons pas trouvé de contact par la date de création" << std::endl;
    }

    if(contactRecherche1==Contact2)
    {
        std::cout << "Nous avons trouvé le bon contact par la date de création" << std::endl;
    }
    else
    {
       std::cout << "Nous n'avons pas trouvé de contact par la date de création" << std::endl;
    }

    std::cout << std::endl << "test de la fonction findByDateModifBetween" << std::endl;
    contactRecherche1 = gestionnaireContact.findByDateModifBetween(Contact1->getDateLastUpdate(), Contact3->getDateLastUpdate());

    if(contactRecherche1==Contact2)
    {
        std::cout << "Nous avons trouvé le bon contact par la date de modification" << std::endl;
    }
    else
    {
       std::cout << "Nous n'avons pas trouvé de contact par la date de modification" << std::endl;
    }

    if(contactRecherche1==Contact3)
    {
        std::cout << "Nous avons trouvé le bon contact par la date de modification" << std::endl;
    }
    else
    {
       std::cout << "Nous n'avons pas trouvé de contact par la date de modification" << std::endl;
    }

    std::cout << endl << "Test de listAllInteractions" <<endl;
    list<InteractionEntity*> listInteraction= gestionnaireContact.listAllInteractions(Contact1);

    for (auto i: listInteraction)
    {
            std::cout << *i << std::endl;
    }

    listInteraction = gestionnaireContact.listAllInteractions(Contact2);

    if (listInteraction.size()==0){
        cout << "La liste est vide le contact n'a pas d'interaction" << endl;
    }

    */
    QApplication a(argc, argv);
    MainWindow w(nullptr, gestionnaireContact, gestionnaireInteraction, gestionnaireTodo);
    w.show();

    return a.exec();

}
