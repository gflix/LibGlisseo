#ifndef NETWORKING_PROTOCOL_TELNETSERVER_H_
#define NETWORKING_PROTOCOL_TELNETSERVER_H_

#include <glisseo/network/protocol/GenericServer.h>
#include <glisseo/network/protocol/GenericTelnetService.h>
#include <glisseo/network/protocol/TelnetServerConnection.h>

namespace Glisseo {

/// Implementation of a telnet server
class TelnetServer: public GenericServer<TelnetServerConnection> {
public:
    /// Initializes the telnet server
    TelnetServer(
        GenericTelnetService* telnetService,
        int port,
        Protocol protocol = Protocol::IPV4,
        const std::string& defaultPrompt = "> ");
    virtual ~TelnetServer() = default;

    /// Changes the default prompt for further telnet sessions
    void setDefaultPrompt(const std::string& defaultPrompt);
    /// Changes the welcome message for further telnet sessions
    void setWelcomeMessage(const std::string& welcomeMessage);

protected:
    /// Overridden thread task
    virtual bool task(const Select& select) override;

private:
    GenericTelnetService* telnetService;
    std::string defaultPrompt;
    std::string welcomeMessage;
};

} /* namespace Glisseo */

#endif /* NETWORKING_PROTOCOL_TELNETSERVER_H_ */
