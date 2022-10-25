#include "contactinteractionentity.h"


ContactInteractionEntity::ContactInteractionEntity(ContactEntity contact, InteractionEntity interaction)
{
    contactEntity=contact;
    interactionEntity=interaction;
}

const ContactEntity &ContactInteractionEntity::getContactEntity() const
{
    return contactEntity;
}

const InteractionEntity &ContactInteractionEntity::getInteractionEntity() const
{
    return interactionEntity;
}

bool operator==(ContactInteractionEntity a, ContactInteractionEntity b){
    return  a.contactEntity == b.contactEntity &&
            a.interactionEntity == b.interactionEntity;
}
