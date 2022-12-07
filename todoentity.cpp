#include "todoentity.h"

TodoEntity::TodoEntity()
{
    dateAjoutTodo=year_month_day{floor<days>(system_clock::now())};
}

TodoEntity::TodoEntity(std::string contenu, year_month_day dateAjout)
{
    contenuTodo=contenu;
    dateAjoutTodo=dateAjout;
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

const year_month_day &TodoEntity::getDateAjoutTodo() const
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
