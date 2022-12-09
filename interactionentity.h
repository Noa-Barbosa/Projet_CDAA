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
     * @param id l'id de l'interaction en base
     * @param contenu le contenu sous forme d'une chaine de l'interaction
     * @param dateAjout la date d'ajout de l'interaction recuperer depuis la BDD
     */
    InteractionEntity(int id, std::string contenu, year_month_day dateAjout);

    ~InteractionEntity();

    /**
     * @brief Assesseur du contenu de l'interaction
     * @return la chaine qui donne le contenu de l'interaction
     */
    const std::string &getContenuInteraction() const;

    /**
     * @brief Mutateur du contenu de l'interaction
     * @param newContenuInteraction le nouveau contenu
     */
    void setContenuInteraction(const std::string &newContenuInteraction);

    /**
     * @brief Assesseur de la date d'ajout d'une interaction
     * @return la date d'ajout de l'interaction
     */
    const year_month_day &getDateAjoutInteraction() const;

    int getIdInteraction() const;

private:

    /**
     * @brief Id de l'interaction en base
     */
    int idInteraction;

    /**
     * @brief Texte de l'interaction
     */
    std::string contenuInteraction;

    /**
     * @brief Date d'ajout de l'interaction
     */
    year_month_day dateAjoutInteraction;

    /**
    * @brief Fonction amie qui surcharge l'operateur << pour l'affichage de l'interaction
    */
    friend std::ostream& operator<< (ostream& os, const InteractionEntity& interaction);

    /**
     * @brief Compare le contenu et la date d'ajout des deux interactions
     * @param a la premiere interaction a comparer
     * @param b la deuxieme interaction a comparer
     * @return vrai si les deux interactions sont identiques faux sinon
     */
    friend bool operator==(InteractionEntity a, InteractionEntity b);
};

#endif // INTERACTIONENTITY_H
