#include "interactiontodoentity.h"


InteractionTodoEntity::InteractionTodoEntity(int id, InteractionEntity *interaction, TodoEntity *todo)
{
    idInteractionTodo=id;
    idInteraction=interaction->getIdInteraction();
    interactionEntity=interaction;
    idTodo=todo->getIdTodo();
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

int InteractionTodoEntity::getIdInteractionTodo() const
{
    return idInteractionTodo;
}

int InteractionTodoEntity::getIdInteraction() const
{
    return idInteraction;
}

int InteractionTodoEntity::getIdTodo() const
{
    return idTodo;
}

bool operator==(InteractionTodoEntity a, InteractionTodoEntity b){
    return  a.interactionEntity == b.interactionEntity &&
            a.todoEntity == b.todoEntity;
}
