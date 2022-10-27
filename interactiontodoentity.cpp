#include "interactiontodoentity.h"


InteractionTodoEntity::InteractionTodoEntity(InteractionEntity *interaction, TodoEntity *todo)
{
    interactionEntity=interaction;
    todoEntity=todo;
}

InteractionEntity *InteractionTodoEntity::getInteractionEntity() const
{
    return interactionEntity;
}

TodoEntity *InteractionTodoEntity::getTodoEntity() const
{
    return todoEntity;
}

bool operator==(InteractionTodoEntity a, InteractionTodoEntity b){
    return  a.interactionEntity == b.interactionEntity &&
            a.todoEntity == b.todoEntity;
}
