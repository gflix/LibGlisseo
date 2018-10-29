#include <stdexcept>
#include <glisseo/utils/Range.h>
#include <glisseo/utils/Trim.h>
#include <glisseo/utils/Split.h>

#define PORT_MIN (1)
#define PORT_MAX (65535)

namespace Glisseo {

std::vector<std::string> split(std::string joinedString, const std::string& separator, bool trim, bool skipEmpty)
{
    if (separator.empty())
    {
        throw std::invalid_argument("empty separator");
    }
    if (joinedString.empty())
    {
        return {};
    }

    std::vector<std::string> strings;
    std::string::size_type position;
    while ((position = joinedString.find(separator)) != std::string::npos)
    {
        std::string element = joinedString.substr(0, position);
        joinedString.erase(0, position + separator.size());

        if (trim)
        {
            element = Glisseo::trim(element);
        }
        if (!element.empty() || !skipEmpty)
        {
            strings.push_back(element);
        }
    }

    if (trim)
    {
        joinedString = Glisseo::trim(joinedString);
    }
    if (!joinedString.empty() || !skipEmpty)
    {
        strings.push_back(joinedString);
    }

    return strings;
}

void splitHostPort(
    const std::string& peer,
    int defaultPort,
    std::string& host,
    int& port)
{
    if (peer.empty())
    {
        throw std::invalid_argument("empty peer argument");
    }
    if (!withinRange(defaultPort, PORT_MIN, PORT_MAX))
    {
        throw std::out_of_range("defaultPort argument is out of range (expect 1-65535)");
    }

    host = peer;
    size_t colonPosition = host.find_last_of(':');
    if (colonPosition != std::string::npos)
    {
        port = std::stoi(host.substr(colonPosition + 1), nullptr, 10);
        host.erase(colonPosition);
    }
    else
    {
        port = defaultPort;
    }

    if (host.empty())
    {
        throw std::invalid_argument("empty host");
    }
    if (!withinRange(port, PORT_MIN, PORT_MAX))
    {
        throw std::out_of_range("port is out of range (expect 1-65535)");
    }
}

} /* namespace Glisseo */
