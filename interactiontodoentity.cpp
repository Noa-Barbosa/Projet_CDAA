#include "interactiontodoentity.h"


InteractionTodoEntity::InteractionTodoEntity(InteractionEntity interaction, TodoEntity todo)
{
    interactionEntity=interaction;
    todoEntity=todo;
}

const InteractionEntity &InteractionTodoEntity::getInteractionEntity() const
{
    return interactionEntity;
}

const TodoEntity &InteractionTodoEntity::getTodoEntity() const
{
    return todoEntity;
}

bool operator==(InteractionTodoEntity a, InteractionTodoEntity b){
    return  a.interactionEntity.getContenuInteraction() == b.interactionEntity.getContenuInteraction() &&
            a.interactionEntity.getDateAjoutInteraction() == b.interactionEntity.getDateAjoutInteraction() &&
            a.todoEntity.getContenuTodo() == b.todoEntity.getContenuTodo() &&
            a.todoEntity.getDateAjoutTodo() == b.todoEntity.getDateAjoutTodo();
}
