#include <glisseo/utils/Log.h>
#include <glisseo/network/protocol/TelnetServerConnection.h>
#include <glisseo/network/protocol/GenericTelnetService.h>

namespace Glisseo {

GenericTelnetService::GenericTelnetService()
{
}

GenericTelnetService::~GenericTelnetService()
{
}

void GenericTelnetService::processLine(const std::string& line, TelnetServerConnection& connection)
{
    if (line == "quit")
    {
        connection.closeConnection();
    }

    connection.send("unknown command \"" + line + "\" (" + std::to_string(line.size()) + ")\n");
}

} /* namespace Glisseo */
