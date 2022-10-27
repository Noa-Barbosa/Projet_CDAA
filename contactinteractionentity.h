#ifndef CONTACTINTERACTIONENTITY_H
#define CONTACTINTERACTIONENTITY_H
#include <contactentity.h>
#include <interactionentity.h>


/**
 * @brief Classe donnant le lien entre un contact et une interaction
 */
class ContactInteractionEntity
{
public:

    /**
     * @brief Constructeur avec parametre de la classe association
     * @param contact Le contact a lie
     * @param interaction L'interaction a lie
     */
    ContactInteractionEntity(ContactEntity *contact, InteractionEntity *interaction);

    /**
     * @brief Assesseur du contact lie
     * @return Le contact
     */
    const ContactEntity *getContactEntity() const;

    /**
     * @brief Assesseur de l'interaction lie
     * @return L'interaction
     */
    const InteractionEntity *getInteractionEntity() const;

private:

    /**
     * @brief Le contact lie a l'interaction
     */
    ContactEntity *contactEntity;

    /**
     * @brief L'interaction lie au contact
     */
    InteractionEntity *interactionEntity;

    /**
     * @brief Compare l'interaction et le contact de chacun des objets en parametres
     * @param a le premier objet a comparer
     * @param b le deuxieme objet a comparer
     * @return vrai si les objets sont identiques faux sinon
     */
    friend bool operator==(ContactInteractionEntity a, ContactInteractionEntity b);

};

#endif // CONTACTINTERACTIONENTITY_H
