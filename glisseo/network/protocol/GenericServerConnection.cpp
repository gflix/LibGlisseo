#include <glisseo/network/protocol/GenericServerConnection.h>

namespace Glisseo {

GenericServerConnection::GenericServerConnection(
    const std::string& identifier,
    int descriptor,
    const std::string& peer):
    GenericThread(identifier),
    descriptor(descriptor),
    peer(peer)
{
}

void GenericServerConnection::closeConnection(void)
{
    if (descriptor < 0) {
        return;
    }

    close(descriptor);
    descriptor = -1;
    threadFinished = true;
}

void GenericServerConnection::send(const std::string& message)
{
    ssize_t bytesWritten = ::write(descriptor, message.c_str(), message.size());
    if (bytesWritten < 0)
    {
        closeConnection();
    }
}

const std::string& GenericServerConnection::getPeer(void) const
{
    return
        peer;
}

void GenericServerConnection::updateDescriptors(Select& select)
{
    select.addReadDescriptor(descriptor);
}

} /* namespace Glisseo */
