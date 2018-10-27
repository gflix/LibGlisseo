#include <stdexcept>
#include <glisseo/network/tcp/GenericTcp.h>

namespace Glisseo {

GenericTcp::GenericTcp():
    GenericDescriptor()
{
}

bool GenericTcp::isConnected(void) const
{
    return
        descriptorIsValid();
}

} /* namespace Glisseo */
