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
     * @brief Constructeur avec parametre du gestionnaire
     * @param gestionnaire le gestionnaire de listes de l'application
     */
    GestionnaireInteraction(GestionnaireListes *gestionnaire);
    /**
     * @brief Ajoute l'interaction a liste d'interaction
     * @brief Va egalement ajouter l'association contact/interaction lie au contact en parametre
     * @param interaction L'interaction a ajoute
     * @param contact Le contact auquel est lie l'interaction
     */
    void addInteraction(InteractionEntity* interaction, ContactEntity* contact);

    /**
     * @brief Modifie l'interaction en premier parametre avec les valeurs contenu dans l'interaction en deuxieme parametre
     * @param interaction La premiere interaction a modifier
     * @param interactionModif L'interaction contenant les modifications a apporter sur la deuxieme (il faut laisser la meme valeur que dans la premiere interaction si on ne veut pas modifier)
     */
    void editInteraction(InteractionEntity* interaction, InteractionEntity* interactionModif);

    /**
     * @brief Supprime l'interaction de la liste des interactions ainsi que toutes les associations qui lui sont liees
     * @param interaction L'interaction a supprimer
     */
    void deleteInteraction(InteractionEntity* interaction);

private:

    /**
     * @brief Les gestionnaire de listes de l'application
     */
    GestionnaireListes *gestionnaireListes;

};

#endif // GESTIONNAIREINTERACTION_H
