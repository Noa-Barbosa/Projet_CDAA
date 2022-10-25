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
     * @param Le contact a lie
     * @param L'interaction a lie
     */
    ContactInteractionEntity(ContactEntity contact, InteractionEntity interaction);
    /**
     * @brief Assesseur du contact lie
     * @return Le contact
     */
    const ContactEntity &getContactEntity() const;

    /**
     * @brief Assesseur de l'interaction lie
     * @return L'interaction
     */
    const InteractionEntity &getInteractionEntity() const;

private:

    /**
     * @brief Le contact lie a l'interaction
     */
    ContactEntity contactEntity;

    /**
     * @brief L'interaction lie au contact
     */
    InteractionEntity interactionEntity;

    friend bool operator==(ContactInteractionEntity a, ContactInteractionEntity b);

};

#endif // CONTACTINTERACTIONENTITY_H
