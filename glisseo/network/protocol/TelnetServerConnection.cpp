#include <cstring>
#include <glisseo/utils/Log.h>
#include <glisseo/network/protocol/TelnetServerConnection.h>

#define TELNET_STREAM_BUFFER (128)

namespace Glisseo {

TelnetServerConnection::TelnetServerConnection(
    GenericTelnetService* telnetService,
    int descriptor,
    const std::string& peer,
    const std::string& prompt,
    const std::string& welcomeMessage):
    GenericServerConnection("TelnetServerConnection(" + peer + ")", descriptor, peer),
    telnetService(telnetService),
    prompt(prompt),
    welcomeMessage(welcomeMessage)
{
}

TelnetServerConnection::~TelnetServerConnection()
{
}

bool TelnetServerConnection::setup(void)
{
    send("\n");
    sendWelcomeMessage();
    send("\n");
    send("\n");
    sendPrompt();
    return true;
}

bool TelnetServerConnection::task(const Select& select)
{
    if (!select.readDescriptorIsSet(descriptor))
    {
        return true;
    }

    char buffer[TELNET_STREAM_BUFFER];
    bzero(buffer, sizeof(buffer));

    ssize_t bytesRead = ::read(descriptor, buffer, sizeof(buffer));
    if (bytesRead <= 0)
    {
        closeConnection();
        return true;
    }

    socketBuffer += std::string(buffer, bytesRead);

    std::string line;
    while (getLineFromSocketBuffer(line))
    {
        if (telnetService)
        {
            telnetService->processLine(line, *this);
        }

        sendPrompt();
    }

    return true;
}

void TelnetServerConnection::sendPrompt(void)
{
    send(prompt);
}

void TelnetServerConnection::sendWelcomeMessage(void)
{
    send(welcomeMessage);
}

bool TelnetServerConnection::getLineFromSocketBuffer(std::string& line)
{
    line.clear();

    size_t endOfLinePosition = socketBuffer.find_first_of("\r\n");
    if (endOfLinePosition == std::string::npos)
    {
        return false;
    }

    line = socketBuffer.substr(0, endOfLinePosition);
    socketBuffer.erase(0, endOfLinePosition);

    size_t nextLinePosition = socketBuffer.find_first_not_of("\r\n");
    if (nextLinePosition == std::string::npos)
    {
        socketBuffer.clear();
    }
    else
    {
        socketBuffer.erase(0, nextLinePosition);
    }

    return true;
}

} /* namespace Glisseo */
