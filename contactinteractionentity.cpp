#include "contactinteractionentity.h"


ContactInteractionEntity::ContactInteractionEntity(int id,ContactEntity *contact, InteractionEntity *interaction)
{
    idContactInteraction = id;
    idContactEntity=contact->getIdContact();
    idInteractionEntity=interaction->getIdInteraction();
    contactEntity=contact;
    interactionEntity=interaction;
}

int ContactInteractionEntity::getIdContactEntity() const
{
    return idContactEntity;
}

int ContactInteractionEntity::getIdInteractionEntity() const
{
    return idInteractionEntity;
}

ContactEntity *ContactInteractionEntity::getContactEntity() const
{
    return contactEntity;
}

InteractionEntity *ContactInteractionEntity::getInteractionEntity() const
{
    return interactionEntity;
}

bool operator==(ContactInteractionEntity a, ContactInteractionEntity b){
    return  a.idContactEntity == b.idContactEntity &&
            a.idInteractionEntity == b.idInteractionEntity;
}
