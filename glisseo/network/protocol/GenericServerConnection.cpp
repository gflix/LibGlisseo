#include <glisseo/network/protocol/GenericServerConnection.h>

namespace Flix {

GenericServerConnection::GenericServerConnection(
    const std::string& identifier,
    int descriptor,
    const std::string& clientConnection):
    GenericThread(identifier),
    descriptor(descriptor),
    clientConnection(clientConnection)
{
}

GenericServerConnection::~GenericServerConnection()
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

void GenericServerConnection::updateDescriptors(Select& select)
{
    select.addReadDescriptor(descriptor);
}

} /* namespace Flix */
