#include "gestionnaireinteraction.h"

GestionnaireInteraction::GestionnaireInteraction(GestionnaireListes gestionnaire)
{
    gestionnaireListes=gestionnaire;
}

void GestionnaireInteraction::addInteraction(InteractionEntity interaction, ContactEntity contact)
{
    gestionnaireListes.addInteraction(interaction,contact);
}

list<InteractionEntity> GestionnaireInteraction::getListInteractionEntity()
{
    return gestionnaireListes.getListInteractionEntity();
}
