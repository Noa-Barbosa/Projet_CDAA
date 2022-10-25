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

    GestionnaireListes();

    const list<ContactEntity *> &getListContactEntity() const;
    void setListContactEntity(const list<ContactEntity *> &newListContactEntity);
    const list<InteractionEntity *> &getListInteractionEntity() const;
    void setListInteractionEntity(const list<InteractionEntity *> &newListInteractionEntity);
    const list<TodoEntity *> &getListTodoEntity() const;
    void setListTodoEntity(const list<TodoEntity *> &newListTodoEntity);
    const list<ContactInteractionEntity *> &getListContactInteractionEntity() const;
    void setListContactInteractionEntity(const list<ContactInteractionEntity *> &newListContactInteractionEntity);
    const list<InteractionTodoEntity *> &getListInteractionTodoEntity() const;
    void setListInteractionTodoEntity(const list<InteractionTodoEntity *> &newListInteractionTodoEntity);

    /**
     * @brief Verifie si l'interaction existe ou pas dans la liste des interactions
     * @param L'interaction recherche
     * @return vrai si elle existe faux sinon
     */
    bool isInteractionInList(InteractionEntity *interactionRecherche);

private:
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

#endif // GESTIONNAIRELISTES_H
