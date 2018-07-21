#include <glisseo/utils/GenericDescriptor.h>

namespace Glisseo {

GenericDescriptor::GenericDescriptor():
    descriptor(INVALID_DESCRIPTOR)
{
}

int GenericDescriptor::getDescriptor(void) const
{
    return
        descriptor;
}

bool GenericDescriptor::descriptorIsValid(void) const
{
    return
        descriptor != INVALID_DESCRIPTOR;
}

void GenericDescriptor::invalidateDescriptor(void)
{
    descriptor = INVALID_DESCRIPTOR;
}

} /* namespace Glisseo */
