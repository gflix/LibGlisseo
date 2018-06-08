#include <glisseo/network/protocol/NetstringEncoder.h>
#include <glisseo/network/protocol/GenericNetstringClient.h>

namespace Flix {

GenericNetstringClient::GenericNetstringClient()
{
}

GenericNetstringClient::~GenericNetstringClient()
{
}

void GenericNetstringClient::connect(std::string host, int port)
{
    netstringDecoder.resetBuffer();
    TcpClient::connect(host, port);
}

void GenericNetstringClient::sendMessage(const std::string& message) const
{
    send(toNetstring(message));
}

void GenericNetstringClient::receiveMessages(Messages& messages)
{
    messages.clear();

    std::string data;
    receive(data);

    if (data.empty())
    {
        throw std::runtime_error("connection was closed");
    }

    netstringDecoder.appendText(data);

    while (netstringDecoder.hasMessage())
    {
        messages.push_back(netstringDecoder.getMessage());
    }
}

} /* namespace Flix */
