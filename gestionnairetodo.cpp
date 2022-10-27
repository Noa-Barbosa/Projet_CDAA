#include "gestionnairetodo.h"

GestionnaireTodo::GestionnaireTodo(GestionnaireListes *gestionnaire)
{
    gestionnaireListes=gestionnaire;
}

void GestionnaireTodo::addTodo(TodoEntity *todo, InteractionEntity *interaction)
{
    //a chaque fois qu'on veut faire une operation sur une liste on recupere la liste actuelle avec le gestionnaire de liste (plus tard se sera un appel sur la base)
    auto listTodoEntity = gestionnaireListes->getListTodoEntity();
    auto listInteractionTodo = gestionnaireListes->getListInteractionTodoEntity();

    //si le todo n'existe pas deja dans la liste
    if(!gestionnaireListes->isTodoInList(todo)){
        listTodoEntity.push_back(todo);
        gestionnaireListes->setListTodoEntity(listTodoEntity);
    }
    else{
        cout << "Le todo existe deja dans la liste il n'a pas ete ajoute" << std::endl;
    }

    InteractionTodoEntity *interactionTodo = new InteractionTodoEntity(interaction, todo);

    if(!gestionnaireListes->isInteractionTodoInList(interactionTodo)){
        listInteractionTodo.push_back(interactionTodo);
        gestionnaireListes->setListInteractionTodoEntity(listInteractionTodo);
    }
    else{
        cout << "Linteraction a deja ce todo les deux n'ont pas ete lie" << std::endl;
    }


}

void GestionnaireTodo::editTodo(TodoEntity *todo, TodoEntity *todoModif)
{
    todo->setContenuTodo(todoModif->getContenuTodo());
}

void GestionnaireTodo::deleteTodo(TodoEntity *todo)
{
    if(gestionnaireListes->isTodoInList(todo)){

        auto listTodoEntity = gestionnaireListes->getListTodoEntity();
        auto listInteractionTodoEntity = gestionnaireListes->getListInteractionTodoEntity();


        list<InteractionTodoEntity*> interactionTodoAsupprimer;

        for(InteractionTodoEntity* interactionTodo : listInteractionTodoEntity)
        {
           if(interactionTodo->getTodoEntity()==todo){
               interactionTodoAsupprimer.push_back(interactionTodo);
           }
        }

        for(InteractionTodoEntity* interactionTodoAsupprimer : interactionTodoAsupprimer)
        {
           listInteractionTodoEntity.remove(interactionTodoAsupprimer);
        }

        listTodoEntity.remove(todo);

        gestionnaireListes->setListTodoEntity(listTodoEntity);
        gestionnaireListes->setListInteractionTodoEntity(listInteractionTodoEntity);

    }
    else{
        cout << "Le todo n'existe pas rien n'a ete fait" << std::endl;
    }
}
