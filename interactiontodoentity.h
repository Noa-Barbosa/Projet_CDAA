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

    friend bool operator==(InteractionTodoEntity a, InteractionTodoEntity b);
};

#endif // INTERACTIONTODOENTITY_H
