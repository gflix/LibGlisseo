#include <arpa/inet.h>
#include <cstring>
#include <glisseo/utils/Log.h>
#include <glisseo/network/protocol/TelnetServer.h>

namespace Flix {

TelnetServer::TelnetServer(
    GenericTelnetService* telnetService,
    int port,
    Protocol protocol,
    const std::string& defaultPrompt):
    GenericServer<TelnetServerConnection>("TelnetServer", port, protocol),
    telnetService(telnetService),
    defaultPrompt(defaultPrompt)
{
}

TelnetServer::~TelnetServer()
{
}

void TelnetServer::setDefaultPrompt(const std::string& defaultPrompt)
{
    this->defaultPrompt = defaultPrompt;
}

void TelnetServer::setWelcomeMessage(const std::string& welcomeMessage)
{
    this->welcomeMessage = welcomeMessage;
}

bool TelnetServer::task(const Select& select)
{
    manageClientConnections(select, [=](int clientDescriptor, const std::string& clientConnection) -> TelnetServerConnection* {
       return
           new TelnetServerConnection(telnetService, clientDescriptor, clientConnection, defaultPrompt, welcomeMessage);
    });

    return true;
}

} /* namespace Flix */
