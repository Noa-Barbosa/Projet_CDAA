#include "todoentity.h"

TodoEntity::TodoEntity()
{
    dateAjoutTodo=floor<days>(system_clock::now());
}

TodoEntity::TodoEntity(std::string contenu)
{
    contenuTodo=contenu;
    dateAjoutTodo=floor<days>(system_clock::now());
}

TodoEntity::~TodoEntity(){

}

const std::string &TodoEntity::getContenuTodo() const
{
    return contenuTodo;
}

void TodoEntity::setContenuTodo(const std::string &newContenuTodo)
{
    contenuTodo = newContenuTodo;
}

const sys_days &TodoEntity::getDateAjoutTodo() const
{
    return dateAjoutTodo;
}

std::ostream& operator<< (ostream& os, const TodoEntity& todo)
{
    os << todo.getContenuTodo() << ' ' << todo.getDateAjoutTodo();
    return os;
}

bool operator==(TodoEntity a, TodoEntity b){
    return a.getContenuTodo() == b.getContenuTodo() &&
            a.getDateAjoutTodo() == b.getDateAjoutTodo();
}
