#ifndef NETWORKING_PROTOCOL_TELNETSERVER_H_
#define NETWORKING_PROTOCOL_TELNETSERVER_H_

#include <glisseo/network/protocol/GenericServer.h>
#include <glisseo/network/protocol/GenericTelnetService.h>
#include <glisseo/network/protocol/TelnetServerConnection.h>

namespace Glisseo {

class TelnetServer: public GenericServer<TelnetServerConnection> {
public:
    TelnetServer(
        GenericTelnetService* telnetService,
        int port,
        Protocol protocol = Protocol::IPV4,
        const std::string& defaultPrompt = "> ");
    virtual ~TelnetServer() = default;

    void setDefaultPrompt(const std::string& defaultPrompt);
    void setWelcomeMessage(const std::string& welcomeMessage);

protected:
    virtual bool task(const Select& select) override;

private:
    GenericTelnetService* telnetService;
    std::string defaultPrompt;
    std::string welcomeMessage;
};

} /* namespace Glisseo */

#endif /* NETWORKING_PROTOCOL_TELNETSERVER_H_ */
