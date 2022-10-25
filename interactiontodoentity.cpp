#include "interactiontodoentity.h"


InteractionTodoEntity::InteractionTodoEntity(InteractionEntity *interaction, TodoEntity *todo)
{
    interactionEntity=interaction;
    todoEntity=todo;
}

const InteractionEntity *InteractionTodoEntity::getInteractionEntity() const
{
    return interactionEntity;
}

const TodoEntity *InteractionTodoEntity::getTodoEntity() const
{
    return todoEntity;
}

bool operator==(InteractionTodoEntity a, InteractionTodoEntity b){
    return  a.interactionEntity == b.interactionEntity &&
            a.todoEntity == b.todoEntity;
}
