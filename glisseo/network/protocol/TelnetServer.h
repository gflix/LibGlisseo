#ifndef NETWORKING_PROTOCOL_TELNETSERVER_H_
#define NETWORKING_PROTOCOL_TELNETSERVER_H_

#include <glisseo/utils/GenericThread.h>
#include <glisseo/network/tcp/TcpServer.h>
#include <glisseo/network/protocol/GenericTelnetService.h>
#include <glisseo/network/protocol/TelnetServerConnection.h>

namespace Flix {

class TelnetServer: public GenericThread {
public:
    TelnetServer(
        GenericTelnetService* telnetService,
        int port,
        Protocol protocol = Protocol::IPV4,
        const std::string& defaultPrompt = "> ");
    virtual ~TelnetServer();

    void setDefaultPrompt(const std::string& defaultPrompt);
    void setWelcomeMessage(const std::string& welcomeMessage);

protected:
    virtual bool setup(void) override;
    virtual bool task(const Select& select) override;
    virtual void updateDescriptors(Select& select) override;

private:
    GenericTelnetService* telnetService;
    int port;
    Protocol protocol;
    std::string defaultPrompt;
    std::string welcomeMessage;

    TcpServer tcpServer;
    TelnetServerConnections connectionThreads;
};

} /* namespace Flix */

#endif /* NETWORKING_PROTOCOL_TELNETSERVER_H_ */
