#ifndef GESTIONNAIREBDD_H
#define GESTIONNAIREBDD_H
#include <iostream>
#include <QtSql>
#include <contactentity.h>
#include <interactionentity.h>
#include <todoentity.h>
#include <contactinteractionentity.h>
#include <interactiontodoentity.h>

using namespace std;

/**
 * @brief Classe qui gere les actions sur la BDD et les listes utilisees dans notre programme
 */
class GestionnaireBDD
{

public:

    /**
     * @brief Constructeur vide la classe
     * @param path le chemin jusqu'a la base SQLite
     */
    GestionnaireBDD(const QString& path);

    /**
     * @brief Fonction qui lance une requete pour commencer une transaction (utilise pour nos tests)
     */
    void beginTransaction();

    /**
     * @brief Fonction qui lance une requete pour rollback une transaction (utilise pour nos tests)
     */
    void rollbackTransaction();

    /**
     * @brief Assesseur de la liste des contacts
     * @return la liste des contacts
     */
    const list<ContactEntity *> &getListContactEntity() const;

    /**
     * @brief Mutateur de la liste des contacts
     * @param newListContactEntity la nouvelle liste
     */
    void setListContactEntity(const list<ContactEntity *> &newListContactEntity);

    /**
     * @brief Assesseur de la liste des interactions
     * @return la liste des interactions
     */
    const list<InteractionEntity *> &getListInteractionEntity() const;

    /**
     * @brief Mutateur de la liste des interactions
     * @param newListInteractionEntity la nouvelle liste
     */
    void setListInteractionEntity(const list<InteractionEntity *> &newListInteractionEntity);

    /**
     * @brief Assesseur de la liste des todos
     * @return la liste des todos
     */
    const list<TodoEntity *> &getListTodoEntity() const;

    /**
     * @brief Mutateur de la liste des todos
     * @param newListTodoEntity la nouvelle liste
     */
    void setListTodoEntity(const list<TodoEntity *> &newListTodoEntity);

    /**
     * @brief Assesseur de la liste des contactinteractions
     * @return la liste des contactinteractions
     */
    const list<ContactInteractionEntity *> &getListContactInteractionEntity() const;

    /**
     * @brief Mutateur de la liste des contactinteractions
     * @param newListContactInteractionEntity la nouvelle liste
     */
    void setListContactInteractionEntity(const list<ContactInteractionEntity *> &newListContactInteractionEntity);

    /**
     * @brief Assesseur de la liste des interactiontodos
     * @return la liste des interactiontodos
     */
    const list<InteractionTodoEntity *> &getListInteractionTodoEntity() const;

    /**
     * @brief Mutateur de la liste des interactiontodos
     * @param newListInteractionTodoEntity la nouvelle liste
     */
    void setListInteractionTodoEntity(const list<InteractionTodoEntity *> &newListInteractionTodoEntity);

    /**
     * @brief Verifie si le contact existe ou pas dans la liste des contacts
     * @param contactRecherche Le contact recherche
     * @return vrai s'il existe faux sinon
     */
    bool isContactInList(ContactEntity *contactRecherche);

    /**
     * @brief Verifie si l'interaction existe ou pas dans la liste des interactions
     * @param interactionRecherche L'interaction recherche
     * @return vrai si elle existe faux sinon
     */
    bool isInteractionInList(InteractionEntity *interactionRecherche);

    /**
     * @brief Verifie si le todo existe ou pas dans la liste des todos
     * @param todoRecherche Le todo recherche
     * @return vrai s'il existe faux sinon
     */
    bool isTodoInList(TodoEntity *todoRecherche);

    /**
     * @brief Verifie si le contactinteraction existe ou pas dans la liste des contactinteractions
     * @param contactInteractionRecherche Le contact interaction recherche
     * @return vrai s'il existe faux sinon
     */
    bool isContactInteractionInList(ContactInteractionEntity* contactInteractionRecherche);

    /**
     * @brief Verifie si l'interactiontodo existe ou pas dans la liste des todointeractions
     * @param interactionTodoRecherche Le contact interaction recherche
     * @return vrai s'il existe faux sinon
     */
    bool isInteractionTodoInList(InteractionTodoEntity* interactionTodoRecherche);

    /**
     * @brief Met a jour la liste des contacts depuis la BDD
     * @return true si la requete c'est bien passe false sinon
     */
    bool hydrateContactList();

    /**
     * @brief Insere un nouveau contact dans la BDD
     * @param contact le contact a ajoute
     * @return true si la requete c'est bien passe false sinon
     */
    bool insertContact(ContactEntity * contact);

    /**
     * @brief Met a jour le contact avec l'id correpondant a celui du parametres selon les attributs du contact en parametre
     * @param contact le pointeur sur le contact a modifie (cela permet de modifier directement l'objet sans modifier la liste)
     * @param contactEntityModifie le pointeur sur le contact qui contient les modifications
     * @return true si la requete c'est bien passe false sinon
     */
    bool updateContact(ContactEntity * contact, ContactEntity * contactEntityModifie);

    /**
     * @brief Suppression d'un contact dans la BDD
     * @param contact le contact a supprimer
     * @return true si la requete c'est bien passe false sinon
     */
    bool deleteContact(ContactEntity * contact);

    /**
     * @brief hydrateInteractionList
     * @return true si la requete c'est bien passe false sinon
     */
    bool hydrateInteractionList();

    /**
     * @brief Insere une interaction dans la BDD
     * @param interaction l'interaction a ajoute
     * @return true si la requete c'est bien passe false sinon
     */
    bool insertInteraction(InteractionEntity * interaction);

    /**
     * @brief Met a jour le contenu de l'interaction
     * @param interaction l'interaction que l'on veut modifier
     * @param interactionModifie les modifications a apporter sur l'interaction
     * @return true si la requete c'est bien passe false sinon
     */
    bool updateInteraction(InteractionEntity * interaction, InteractionEntity * interactionModifie);

    /**
     * @brief Supprime une interaction de la BDD
     * @param interaction l'interaction a supprimer
     * @return true si la requete c'est bien passe false sinon
     */
    bool deleteInteraction(InteractionEntity * interaction);

    /**
     * @brief Remplie la liste des todos depuis la BDD
     * @return true si la requete c'est bien passe false sinon
     */
    bool hydrateTodoList();

    /**
     * @brief Insere un nouveau todo dans la base
     * @param todo le todo a inserer
     * @return true si la requete c'est bien passe false sinon
     */
    bool insertTodo(TodoEntity * todo);

    /**
     * @brief Met a jour le todo en parametre a partir deuxieme todo
     * @param todo le todo a modifier
     * @param todoModifie le todo avec les modifications
     * @return true si la requete c'est bien passe false sinon
     */
    bool updateTodo(TodoEntity * todo, TodoEntity * todoModifie);

    /**
     * @brief Supprime le todo dans la BDD
     * @param todo le todo a supprimer
     * @return true si la requete c'est bien passe false sinon
     */
    bool deleteTodo(TodoEntity * todo);

    /**
     * @brief Remplie la liste des associations contactinteraction
     * @return true si la requete c'est bien passe false sinon
     */
    bool hydrateContactInteractionList();

    /**
     * @brief Insere une association contact interaction dans la base
     * @param contactInteraction le contact interaction a inserer
     * @return true si la requete c'est bien passe false sinon
     */
    bool insertContactInteraction(ContactInteractionEntity * contactInteraction);

    /**
     * @brief Remplie la liste des interactions todo depuis la base
     * @return true si la requete c'est bien passe false sinon
     */
    bool hydrateInteractionTodoList();

    /**
     * @brief Insere une association interactiontodo dans la base
     * @param interactionTodo l'interaction todo a ajoute
     * @return true si la requete c'est bien passe false sinon
     */
    bool insertInteractionTodo(InteractionTodoEntity * interactionTodo);


private:

    /**
      * @brief La base de donnees du CRM
      */
     QSqlDatabase db;
    /**
     * @brief Liste des contacts du programme
     */
    list<ContactEntity*> listContactEntity;

    /**
     * @brief Liste des interactions du programme
     */
    list<InteractionEntity*> listInteractionEntity;

    /**
     * @brief Liste des todos du programme
     */
    list<TodoEntity*> listTodoEntity;

    /**
     * @brief Liste des associations contact interaction du programme
     */
    list<ContactInteractionEntity*> listContactInteractionEntity;

    /**
     * @brief Liste des associations interaction todo du programme
     */
    list<InteractionTodoEntity*> listInteractionTodoEntity;

};

#endif // GESTIONNAIREBDD_H
