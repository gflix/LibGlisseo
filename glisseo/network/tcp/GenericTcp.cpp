#include <stdexcept>
#include <glisseo/network/tcp/GenericTcp.h>

namespace Glisseo {

GenericTcp::GenericTcp():
    GenericDescriptor()
{
}

GenericTcp::~GenericTcp()
{
}

bool GenericTcp::isConnected(void) const
{
    return
        descriptorIsValid();
}

bool GenericTcp::withinRange(int value, int min, int max) const
{
    return
        value >= min &&
        value <= max;
}

} /* namespace Glisseo */
