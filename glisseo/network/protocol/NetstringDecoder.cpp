#include <stdexcept>
#include <glisseo/network/protocol/NetstringDecoder.h>

namespace Glisseo {

NetstringDecoder::NetstringDecoder():
    colonPosition(std::string::npos),
    messageLength(0)
{
}

void NetstringDecoder::appendText(const std::string& text)
{
    buffer += text;
}

void NetstringDecoder::checkBuffer(void)
{
    colonPosition = buffer.find_first_of(':');
    // if buffer has enough bytes but colon was not found within the first 6 bytes
    if (colonPosition == std::string::npos && buffer.size() >= 6)
    {
        throw std::runtime_error("colon separator not found");
    }
    if (colonPosition != std::string::npos)
    {
        // The colon shall not be the first character
        if (colonPosition == 0)
        {
            throw std::runtime_error("length value is missing before colon");
        }

        messageLength = std::stoi(buffer.substr(0, colonPosition), nullptr, 10);
        if (buffer.size() > colonPosition + messageLength + 1)
        {
            if (buffer[colonPosition + messageLength + 1] != ',')
            {
                throw std::runtime_error("comma at the end is missing");
            }
        }
    }
}

bool NetstringDecoder::hasMessage(void)
{
    checkBuffer();

    if (colonPosition == std::string::npos)
    {
        return false;
    }

    return
        buffer.size() > colonPosition + messageLength + 1;
}

std::string NetstringDecoder::getMessage(void)
{
    if (!hasMessage())
    {
        throw std::runtime_error("no message available");
    }

    std::string message = buffer.substr(colonPosition + 1, messageLength);
    buffer.erase(0, colonPosition + messageLength + 2);

    return
        message;
}

void NetstringDecoder::resetBuffer(void)
{
    buffer.clear();
}

const std::string& NetstringDecoder::getBuffer(void) const
{
    return
        buffer;
}

} /* namespace Glisseo */
