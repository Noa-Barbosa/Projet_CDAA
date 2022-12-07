#include "interactionentity.h"

InteractionEntity::InteractionEntity()
{
    dateAjoutInteraction=year_month_day{floor<days>(system_clock::now())};
}

InteractionEntity::InteractionEntity(std::string contenu, year_month_day dateAjout)
{
    contenuInteraction=contenu;
    dateAjoutInteraction=dateAjout;
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

const year_month_day &InteractionEntity::getDateAjoutInteraction() const
{
    return dateAjoutInteraction;
}

std::ostream& operator<< (ostream& os, const InteractionEntity& interaction)
{
    os << interaction.getContenuInteraction() << ' ' << interaction.getDateAjoutInteraction();
    return os;
}

bool operator==(InteractionEntity a, InteractionEntity b){
    return a.contenuInteraction == b.contenuInteraction && a.dateAjoutInteraction == b.dateAjoutInteraction;
}
