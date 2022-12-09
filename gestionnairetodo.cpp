#include "gestionnairetodo.h"

GestionnaireTodo::GestionnaireTodo(GestionnaireBDD *gestionnaire)
{
    gestionnaireBDD=gestionnaire;
}

void GestionnaireTodo::addTodo(TodoEntity *todo, InteractionEntity *interaction)
{
    if(gestionnaireBDD->insertTodo(todo)){
        //on a besoin de cherche le todo qu'on vient d'inserer dans la base a partir de la liste
        TodoEntity * todoAvecId = findTodo(todo);
        InteractionTodoEntity * interactionTodo = new InteractionTodoEntity(0,interaction,todoAvecId);
        cout << "Todo ajoute dans la liste" << endl;
        if(gestionnaireBDD->insertInteractionTodo(interactionTodo)){
             cout << "InteractionTodo ajoute dans la liste" << endl;
        }
        else{
            cerr << "Erreur lors de l'insertion en BDD l'InteractionTodo n'a pas ete ajoute dans la liste en dur"<< endl;
        }
    }
    else{
      cerr << "Erreur lors de l'insertion en BDD le todo n'a pas ete ajoute dans la liste en dur"<< endl;
    }
}

void GestionnaireTodo::editTodo(TodoEntity *todo, TodoEntity *todoModif)
{
    if(gestionnaireBDD->updateTodo(todo,todoModif)){
            todo->setContenuTodo(todoModif->getContenuTodo());
            cout << "Todo modifie dans la liste" << endl;
    }
    else{
        cerr << "Erreur lors de l'update en BDD le todo n'a pas ete modifie dans la liste en dur"<< endl;

    }


}

void GestionnaireTodo::deleteTodo(TodoEntity *todo)
{
    if(gestionnaireBDD->deleteTodo(todo)){
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
            cerr << "Le todo n'existe pas rien n'a ete fait" <<std::endl;
        }
    }
    else{
         cerr << "Erreur lors du delete du todo les listes en dur n'ont pas ete modifie" << endl;
    }
}

const list<TodoEntity *> &GestionnaireTodo::getTodoList() const
{
    return gestionnaireBDD->getListTodoEntity();
}

TodoEntity *GestionnaireTodo::findTodo(TodoEntity *todoRecherche)
{
    auto itTodo = std::find_if(gestionnaireBDD->getListTodoEntity().begin(),gestionnaireBDD->getListTodoEntity().end(), [todoRecherche](TodoEntity *todo){return  todo->getContenuTodo()==todoRecherche->getContenuTodo() && todo->getDateAjoutTodo()==todoRecherche->getDateAjoutTodo();});
    return *itTodo;
}

TodoEntity *GestionnaireTodo::findTodoById(int id)
{
    auto itTodo = std::find_if(gestionnaireBDD->getListTodoEntity().begin(),gestionnaireBDD->getListTodoEntity().end(), [id](TodoEntity *todo){return  todo->getIdTodo()==id;});
    return *itTodo;
}
