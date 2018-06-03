#ifndef NETWORKING_PROTOCOL_TELNETSERVERCONNECTION_H_
#define NETWORKING_PROTOCOL_TELNETSERVERCONNECTION_H_

#include <vector>
#include <glisseo/network/protocol/GenericServerConnection.h>
#include <glisseo/network/protocol/GenericTelnetService.h>

namespace Flix {

class TelnetServerConnection: public GenericServerConnection {
public:
    TelnetServerConnection(
        GenericTelnetService* telnetService,
        int descriptor,
        const std::string& clientConnection,
        const std::string& prompt,
        const std::string& welcomeMessage);
    virtual ~TelnetServerConnection();

protected:
    virtual bool setup(void) override;
    virtual bool task(const Select& select) override;

private:
    GenericTelnetService* telnetService;
    std::string prompt;
    std::string welcomeMessage;

    std::string socketBuffer;

    void sendPrompt(void);
    void sendWelcomeMessage(void);

    bool getLineFromSocketBuffer(std::string& line);
};

} /* namespace Flix */

#endif /* NETWORKING_PROTOCOL_TELNETSERVERCONNECTION_H_ */
