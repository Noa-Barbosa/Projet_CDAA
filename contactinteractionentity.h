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
     * @param id du contactinteraction en bdd
     * @param contact Le contact a lie
     * @param interaction L'interaction a lie
     */
    ContactInteractionEntity(int id, ContactEntity *contact, InteractionEntity *interaction);

    /**
     * @brief Asseseur de l'id du contact lie a l'interaction
     * @return l'id
     */
    int getIdContactEntity() const;

    /**
     * @brief Assesseur de l'id de l'interaction lie au contact
     * @return
     */
    int getIdInteractionEntity() const;

    /**
     * @brief Assesseur du contact lie a l'interaction
     * @return le contact
     */
    ContactEntity *getContactEntity() const;

    /**
     * @brief Assesseur de l'interaction lie au contact
     * @return l'interaction
     */
    InteractionEntity *getInteractionEntity() const;

private:

    /**
     * @brief Id de l'assocation contact-interaction en BDD
     */
    int idContactInteraction;
    /**
     * @brief L'id du contact lie a l'interaction
     */
    int idContactEntity;

    /**
     * @brief Le contact lie a l'interaction
     */
    ContactEntity * contactEntity;

    /**
     * @brief L'id de l'interaction lie au contact
     */
    int idInteractionEntity;

    /**
     * @brief L'interaction lie au contact
     */
    InteractionEntity * interactionEntity;

    /**
     * @brief Compare l'interaction et le contact de chacun des objets en parametres
     * @param a le premier objet a comparer
     * @param b le deuxieme objet a comparer
     * @return vrai si les objets sont identiques faux sinon
     */
    friend bool operator==(ContactInteractionEntity a, ContactInteractionEntity b);

};

#endif // CONTACTINTERACTIONENTITY_H
