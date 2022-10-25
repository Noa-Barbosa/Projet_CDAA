#ifndef GESTIONNAIRELISTES_H
#define GESTIONNAIRELISTES_H
#include <iostream>
#include <contactentity.h>
#include <interactionentity.h>
#include <todoentity.h>
#include <contactinteractionentity.h>
#include <interactiontodoentity.h>

using namespace std;

class GestionnaireListes
{

public:

    static GestionnaireListes& getInstance()
           {
               static GestionnaireListes    instance; // Guaranteed to be destroyed.
                                     // Instantiated on first use.
               return instance;
           }

    GestionnaireListes(GestionnaireListes const&) = delete;
    void operator=(GestionnaireListes const&) = delete;

    /**
     * @brief Assesseur de la liste de contacts
     * @return La liste de contacts
     */
    const list<ContactEntity> &getListContactEntity() const;


    /**
     * @brief Assesseur de la liste d'interactions
     * @return La liste d'interactions
     */
    const list<InteractionEntity> &getListInteractionEntity() const;


    /**
     * @brief Assesseur de la liste de todo
     * @return La liste de todo
     */
    const list<TodoEntity> &getListTodoEntity() const;


    /**
     * @brief Assesseur de la liste des associations contacts interactions
     * @return La liste des associations contact interactions
     */
    const list<ContactInteractionEntity> &getListContactInteractionEntity() const;


    /**
     * @brief Assesseur de la liste des associations interactions todos
     * @return La liste des associations interactions todos
     */
    const list<InteractionTodoEntity> &getListInteractionTodoEntity() const;

    void setListContactEntity(const list<ContactEntity> &newListContactEntity);

    void setListInteractionEntity(const list<InteractionEntity> &newListInteractionEntity);

    void setListTodoEntity(const list<TodoEntity> &newListTodoEntity);

    void setListContactInteractionEntity(const list<ContactInteractionEntity> &newListContactInteractionEntity);

    void setListInteractionTodoEntity(const list<InteractionTodoEntity> &newListInteractionTodoEntity);

    /**
     * @brief Verifie si l'interaction existe ou pas dans la liste des interactions
     * @param L'interaction recherche
     * @return vrai si elle existe faux sinon
     */
    bool isInteractionInList(InteractionEntity interactionRecherche);

private:

    GestionnaireListes(){};
    /**
     * @brief Liste des contacts du programme
     */
    list<ContactEntity> listContactEntity;

    /**
     * @brief Liste des interactions du programme
     */
    list<InteractionEntity> listInteractionEntity;

    /**
     * @brief Liste des todos du programme
     */
    list<TodoEntity> listTodoEntity;

    /**
     * @brief Liste des associations contact interaction du programme
     */
    list<ContactInteractionEntity> listContactInteractionEntity;

    /**
     * @brief Liste des associations interaction todo du programme
     */
    list<InteractionTodoEntity> listInteractionTodoEntity;

};

#endif // GESTIONNAIRELISTES_H
