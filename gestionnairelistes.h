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

    void addInteraction(InteractionEntity interaction, ContactEntity contact);

    void editInteraction(InteractionEntity interaction, InteractionEntity interactionModif);

    void deleteInteraction(InteractionEntity interaction);
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

private:

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

    /**
     * @brief Verifie si l'interaction existe ou pas dans la liste des interactions
     * @param L'interaction recherche
     * @return vrai si elle existe faux sinon
     */
    bool isInteractionInList(InteractionEntity interactionRecherche);
};

#endif // GESTIONNAIRELISTES_H
