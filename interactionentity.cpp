#include "interactionentity.h"

InteractionEntity::InteractionEntity()
{
    dateAjoutInteraction=floor<days>(system_clock::now());
}

InteractionEntity::InteractionEntity(std::string contenu)
{
    contenuInteraction=contenu;
    dateAjoutInteraction=floor<days>(system_clock::now());
}

InteractionEntity::~InteractionEntity(){

}

const std::string &InteractionEntity::getContenuInteraction() const
{
    return contenuInteraction;
}

void InteractionEntity::setContenuInteraction(const std::string &newContenuInteraction)
{
    contenuInteraction = newContenuInteraction;
}

const sys_days &InteractionEntity::getDateAjoutInteraction() const
{
    return dateAjoutInteraction;
}

const list<TodoEntity> &InteractionEntity::getListTodo() const
{
    return listTodo;
}

void InteractionEntity::setListTodo(const list<TodoEntity> &newListTodo)
{
    listTodo = newListTodo;
}

std::ostream& operator<< (ostream& os, const InteractionEntity& interaction)
{
    os << interaction.getContenuInteraction() << ' ' << interaction.getDateAjoutInteraction();
    return os;
}
