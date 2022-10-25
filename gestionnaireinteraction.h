#ifndef GESTIONNAIREINTERACTION_H
#define GESTIONNAIREINTERACTION_H
#include <interactionentity.h>
#include <contactinteractionentity.h>
#include <interactiontodoentity.h>
#include <gestionnairelistes.h>
#include <iostream>
#include <date.h>
#include <list>

using namespace date;
using namespace std;
using namespace std::chrono;
/**
 * @brief Classe qui gere les interactions de notre CRM
 */
class GestionnaireInteraction
{
public:

    /**
     * @brief Constructeur avec parametre
     */
    GestionnaireInteraction(GestionnaireListes gestionnaire);

    void addInteraction(InteractionEntity interaction, ContactEntity contact);

    void editInteraction(InteractionEntity interaction, InteractionEntity interactionModif);

    void deleteInteraction(InteractionEntity interaction);

    list<InteractionEntity> getListInteractionEntity();

private:

    GestionnaireListes gestionnaireListes;

};

#endif // GESTIONNAIREINTERACTION_H
