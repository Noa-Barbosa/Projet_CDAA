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
    GestionnaireInteraction();

    /**
     * @brief Ajoute l'interaction a liste d'interaction
     * @brief Va egalement ajouter l'association contact/interaction lie au contact en parametre
     * @param L'interaction a ajoute
     * @param Le contact auquel est lie l'interaction
     */
    void addInteraction(InteractionEntity interaction, ContactEntity contact);

    /**
     * @brief Modifie l'interaction en premier parametre avec les valeurs contenu dans l'interaction en deuxieme parametre
     * @brief La fonction va rechercher toutes les associations pour les modifier
     * @param La premiere interaction a modifier
     * @param L'interaction contenant les modifications a apporter sur la deuxieme (il faut laisser la meme valeur que dans la premiere interaction si on ne veut pas modifier)
     */
    void editInteraction(InteractionEntity interaction, InteractionEntity interactionModif);

    /**
     * @brief Supprime l'interaction de la liste des interactions ainsi que toutes les associations qui lui sont liees
     * @param L'interaction a supprimer
     */
    void deleteInteraction(InteractionEntity interaction);

private:

};

#endif // GESTIONNAIREINTERACTION_H
