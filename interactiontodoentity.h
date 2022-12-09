#ifndef INTERACTIONTODOENTITY_H
#define INTERACTIONTODOENTITY_H
#include <interactionentity.h>
#include <todoentity.h>

/**
 * @brief Classe qui associe une interaction et un todo
 */
class InteractionTodoEntity
{
public:

    /**
     * @brief Constructeur avec parametre de l'interactiontodo
     * @param interaction l'interaction liee au todo
     * @param todo le todo lie a l'interaction
     */
    InteractionTodoEntity(int idInteractionTodo, InteractionEntity *interaction, TodoEntity *todo);

    /**
     * @brief Assesseur de l'interaction
     * @return L'interaction
     */
     InteractionEntity *getInteractionEntity() const;

    /**
     * @brief Asseseur du todo
     * @return Le todo
     */
     TodoEntity *getTodoEntity() const;

     /**
      * @brief Assesseur de l'id de l'interactiontodo
      * @return l'id de l'interaction todo
      */
     int getIdInteractionTodo() const;

     /**
      * @brief Assesseur de l'id de l'interaction
      * @return
      */
     int getIdInteraction() const;

     /**
      * @brief Assesseur de l'id du todo
      * @return
      */
     int getIdTodo() const;

private:

     /**
      * @brief L'id de l'interactiontodo
      */
     int idInteractionTodo;

     /**
      * @brief l'id de l'interaction lie au todo
      */
     int idInteraction;
    /**
     * @brief L'interaction lie au todo
     */
    InteractionEntity *interactionEntity;

    /**
     * @brief L'id du todo lie a l'interaction
     */
    int idTodo;

    /**
     * @brief Le todo lie a l'interaction
     */
    TodoEntity *todoEntity;

    /**
     * @brief Compare l'interaction et le todo des deux objets en parametre
     * @param a la premiere interactiontodo a comparer
     * @param b la deuxieme interactiontodo a comparer
     * @return vrai si elles sont identiques faux sinon
     */
    friend bool operator==(InteractionTodoEntity a, InteractionTodoEntity b);
};

#endif // INTERACTIONTODOENTITY_H
