#include <cstring>
#include <glisseo/utils/Log.h>
#include <glisseo/network/protocol/NetstringEncoder.h>
#include <glisseo/network/protocol/GenericNetstringServerConnection.h>

#define STREAM_BUFFER (128)

namespace Flix {

GenericNetstringServerConnection::GenericNetstringServerConnection(
    const std::string& identifier,
    int descriptor,
    const std::string& peer):
    GenericServerConnection(identifier, descriptor, peer)
{
}

GenericNetstringServerConnection::~GenericNetstringServerConnection()
{
}

void GenericNetstringServerConnection::send(const std::string& message)
{
    GenericServerConnection::send(toNetstring(message));
}

bool GenericNetstringServerConnection::setup(void)
{
    return true;
}

bool GenericNetstringServerConnection::task(const Select& select)
{
    if (!select.readDescriptorIsSet(descriptor))
    {
        return true;
    }

    char buffer[STREAM_BUFFER];
    bzero(buffer, sizeof(buffer));

    ssize_t bytesRead = ::read(descriptor, buffer, sizeof(buffer));
    if (bytesRead <= 0)
    {
        closeConnection();
        return true;
    }

    netstringDecoder.appendText(std::string(buffer, bytesRead));

    try
    {
        while (netstringDecoder.hasMessage())
        {
            processMessage(netstringDecoder.getMessage());
        }
    }
    catch (std::exception& e)
    {
        LOG_WARNING("Broken netstring or protocol error detected (" << e.what() << ")! Closing connection to " << peer << ".");
        closeConnection();
        true;
    }

    return true;
}

} /* namespace Flix */
