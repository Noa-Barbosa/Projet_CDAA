#ifndef INTERACTIONENTITY_H
#define INTERACTIONENTITY_H
#include <iostream>
#include <date.h>
#include <list>
#include <todoentity.h>

using namespace date;
using namespace std;
using namespace std::chrono;

/**
 * @brief Classe décrivant une interaction d'un contact
 */
class InteractionEntity
{
public:
    /**
     * @brief Constructeur vide de l'interaction
     */
    InteractionEntity();

    /**
     * @brief Constructeur parametrique de l'interaction
     * @param contenu le contenu sous forme d'une chaine de l'interaction
     */
    InteractionEntity(std::string contenu);

    ~InteractionEntity();

    /**
     * @brief Assesseur du contenu de l'interaction
     * @return la chaine qui donne le contenu de l'interaction
     */
    const std::string &getContenuInteraction() const;

    /**
     * @brief Mutateur du contenu de l'interaction
     * @param le nouveau contenu
     */
    void setContenuInteraction(const std::string &newContenuInteraction);

    /**
     * @brief Assesseur de la date d'ajout d'une interaction
     * @return la date d'ajout de l'interaction
     */
    const sys_days &getDateAjoutInteraction() const;

private:

    /**
     * @brief Texte de l'interaction
     */
    std::string contenuInteraction;

    /**
     * @brief Date d'ajout de l'interaction
     */
    sys_days dateAjoutInteraction;

    /**
    * @brief Fonction amie qui surcharge l'operateur << pour l'affichage de l'interaction
    */
    friend std::ostream& operator<< (ostream& os, const InteractionEntity& interaction);

    friend bool operator==(InteractionEntity a, InteractionEntity b);
};

#endif // INTERACTIONENTITY_H
