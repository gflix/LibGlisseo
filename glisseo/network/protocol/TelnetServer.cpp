#include <arpa/inet.h>
#include <cstring>
#include <glisseo/utils/Log.h>
#include <glisseo/network/protocol/TelnetServer.h>

namespace Glisseo {

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
    manageClientConnections(select, [=](int clientDescriptor, const std::string& peer) -> TelnetServerConnection* {
       return
           new TelnetServerConnection(telnetService, clientDescriptor, peer, defaultPrompt, welcomeMessage);
    });

    return true;
}

} /* namespace Glisseo */
