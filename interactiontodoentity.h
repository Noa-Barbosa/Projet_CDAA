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
    InteractionTodoEntity(InteractionEntity *interaction, TodoEntity *todo);

    /**
     * @brief Assesseur de l'interaction
     * @return L'interaction
     */
    const InteractionEntity *getInteractionEntity() const;

    /**
     * @brief Asseseur du todo
     * @return Le todo
     */
    const TodoEntity *getTodoEntity() const;

private:

    /**
     * @brief L'interaction lie au todo
     */
    InteractionEntity *interactionEntity;

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
