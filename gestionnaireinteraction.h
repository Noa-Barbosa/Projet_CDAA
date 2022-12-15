#ifndef GESTIONNAIREINTERACTION_H
#define GESTIONNAIREINTERACTION_H
#include <interactionentity.h>
#include <contactinteractionentity.h>
#include <interactiontodoentity.h>
#include <gestionnaireBDD.h>
#include <iostream>
#include <date.h>
#include <list>

using namespace date;
using namespace std;
using namespace std::chrono;

/**
 * @brief Classe qui gere les interactions de notre CRM
 */
class GestionnaireInteraction
{
public:

    /**
     * @brief Constructeur avec parametre du gestionnaire
     * @param gestionnaire le gestionnaire de listes de l'application
     */
    GestionnaireInteraction(GestionnaireBDD *gestionnaire);
    /**
     * @brief Ajoute l'interaction a liste d'interaction
     * @brief Va egalement ajouter l'association contact/interaction lie au contact en parametre
     * @param interaction L'interaction a ajoute
     * @param contact Le contact auquel est lie l'interaction
     */
    void addInteraction(InteractionEntity* interaction, ContactEntity* contact);

    /**
     * @brief Modifie l'interaction en premier parametre avec les valeurs contenu dans l'interaction en deuxieme parametre
     * @param interaction La premiere interaction a modifier
     * @param interactionModif L'interaction contenant les modifications a apporter sur la deuxieme (il faut laisser la meme valeur que dans la premiere interaction si on ne veut pas modifier)
     */
    void editInteraction(InteractionEntity* interaction, InteractionEntity* interactionModif);

    /**
     * @brief Supprime l'interaction de la liste des interactions ainsi que toutes les associations qui lui sont liees
     * @param interaction L'interaction a supprimer
     */
    void deleteInteraction(InteractionEntity* interaction);

    /**
     * @brief Assesseur de la liste des interactions
     * @return la liste des interactions
     */
    const list<InteractionEntity*> &getInteractionList() const;

    /**
     * @brief Assesseur de la liste des interactiontodo
     * @return la liste des interactiontodos
     */
    const list<InteractionTodoEntity *> &getInteractionTodoList() const;

    /**
     * @brief Recherce une interaction egale a l'interaction au paramatre (donc avec le meme contenu et date)
     * @param interactionRecherche l'interaction recherchee
     * @return l'interaction recherchee
     */
    InteractionEntity* findInteraction(InteractionEntity* interactionRecherche);

    /**
     * @brief Recherche l'interaction par son id
     * @param id l'id de l'interaction
     * @return l'interaction recherchee
     */
    InteractionEntity* findInteractionById(int id);

    /**
     * @brief Liste tout les todos d'une interaction
     * @param interaction l'interaction dont on veut rechercher les todos
     * @return la liste des todos
     */
    list<TodoEntity*> listAllTodos(InteractionEntity * interaction);



private:

    /**
     * @brief Les gestionnaire de listes de l'application
     */
    GestionnaireBDD *gestionnaireBDD;

};

#endif // GESTIONNAIREINTERACTION_H
