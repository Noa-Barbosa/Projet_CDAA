#include "gestionnairetodo.h"

GestionnaireTodo::GestionnaireTodo(GestionnaireBDD *gestionnaire)
{
    gestionnaireBDD=gestionnaire;
}

void GestionnaireTodo::addTodo(TodoEntity *todo, InteractionEntity *interaction)
{
    //a chaque fois qu'on veut faire une operation sur une liste on recupere la liste actuelle avec le gestionnaire de liste (plus tard se sera un appel sur la base)
    auto listTodoEntity = gestionnaireBDD->getListTodoEntity();
    auto listInteractionTodo = gestionnaireBDD->getListInteractionTodoEntity();

    //si le todo n'existe pas deja dans la liste
    if(!gestionnaireBDD->isTodoInList(todo)){
        listTodoEntity.push_back(todo);
        gestionnaireBDD->setListTodoEntity(listTodoEntity);
    }
    else{
        cout << "Le todo existe deja dans la liste il n'a pas ete ajoute" << std::endl<<std::endl;
    }

    InteractionTodoEntity *interactionTodo = new InteractionTodoEntity(interaction, todo);

    if(!gestionnaireBDD->isInteractionTodoInList(interactionTodo)){
        listInteractionTodo.push_back(interactionTodo);
        gestionnaireBDD->setListInteractionTodoEntity(listInteractionTodo);
    }
    else{
        cout << "Linteraction a deja ce todo les deux n'ont pas ete lie" << std::endl<<std::endl;
    }


}

void GestionnaireTodo::editTodo(TodoEntity *todo, TodoEntity *todoModif)
{
    todo->setContenuTodo(todoModif->getContenuTodo());
}

void GestionnaireTodo::deleteTodo(TodoEntity *todo)
{
    if(gestionnaireBDD->isTodoInList(todo)){

        auto listTodoEntity = gestionnaireBDD->getListTodoEntity();
        auto listInteractionTodoEntity = gestionnaireBDD->getListInteractionTodoEntity();


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

        gestionnaireBDD->setListTodoEntity(listTodoEntity);
        gestionnaireBDD->setListInteractionTodoEntity(listInteractionTodoEntity);

    }
    else{
        cout << "Le todo n'existe pas rien n'a ete fait" << std::endl<<std::endl;
    }
}
