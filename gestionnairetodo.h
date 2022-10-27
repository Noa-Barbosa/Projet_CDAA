#ifndef GESTIONNAIRETODO_H
#define GESTIONNAIRETODO_H
#include <todoentity.h>
#include <interactionentity.h>
#include <interactiontodoentity.h>
#include <gestionnairelistes.h>
#include <iostream>
#include <date.h>
#include <list>

using namespace date;
using namespace std;
using namespace std::chrono;

/**
 * @brief Classe gerant les actions sur les todos
 */
class GestionnaireTodo
{
public:

    /**
     * @brief Constructeur avec parametre de la classe
     * @param Le gestionnaire de liste du programme
     */
    GestionnaireTodo(GestionnaireListes *gestionnaire);
    /**
     * @brief Ajoute l'interaction a liste d'interaction
     * @brief Va egalement ajouter l'association contact/interaction lie au contact en parametre
     * @param L'interaction a ajoute
     * @param Le contact auquel est lie l'interaction
     */
    void addTodo(TodoEntity* todo, InteractionEntity* interaction);

    /**
     * @brief Modifie le todo en premier parametre avec les valeurs contenu dans le todo en deuxieme parametre
     * @param Le premier todo a modifier
     * @param Le todo contenant les modifications a apporter sur le deuxieme (il faut laisser la meme valeur que dans le premier todo si on ne veut pas modifier)
     */
    void editTodo(TodoEntity* todo, TodoEntity* todoModif);

    /**
     * @brief Supprime l'interaction de la liste des interactions ainsi que toutes les associations qui lui sont liees
     * @param L'interaction a supprimer
     */
    void deleteTodo(TodoEntity* todo);

private:

    /**
     * @brief Le gestionnaire de liste du programme
     */
    GestionnaireListes *gestionnaireListes;
};

#endif // GESTIONNAIRETODO_H
