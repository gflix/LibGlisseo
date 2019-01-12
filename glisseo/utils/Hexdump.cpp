#include <cassert>
#include <cstring>
#include <stdexcept>
#include <glisseo/utils/Hexdump.h>

#define BYTES_PER_LINE (16)

namespace Glisseo {

void hexdumpSlice(std::ostream& stream, const std::string& data, unsigned int addressOffset);

void hexdump(std::ostream& stream, const std::string& data, unsigned int addressOffset)
{
    if (addressOffset & (BYTES_PER_LINE - 1))
    {
        throw std::invalid_argument("addressOffset must be divisible by " + std::to_string(BYTES_PER_LINE));
    }

    if (!data.empty())
    {
        bool firstLine = true;
        for (auto dataIndex = 0; dataIndex < data.size(); dataIndex += BYTES_PER_LINE, addressOffset += BYTES_PER_LINE)
        {
            if (firstLine)
            {
                firstLine = false;
            }
            else
            {
                stream << std::endl;
            }

            hexdumpSlice(stream, data.substr(dataIndex, BYTES_PER_LINE), addressOffset);
        }
    }
    else
    {
        hexdumpSlice(stream, data, addressOffset);
    }
}

void hexdumpSlice(std::ostream& stream, const std::string& data, unsigned int addressOffset)
{
    assert(data.size() <= BYTES_PER_LINE);

    // S0000 0000  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  0000000000000000
    //     0    1 1                                               6 6               7
    // 1   5    0 2                                               0 2               8
    // 12 + BYTES_PER_LINE * 3 + 2 + BYTES_PER_LINE -> 78

    char addressBuffer[10];
    bzero(addressBuffer, sizeof(addressBuffer));
    snprintf(addressBuffer, sizeof(addressBuffer), "%04x %04x", addressOffset >> 16, addressOffset & 0xffff);
    stream << " " << addressBuffer << "  ";

    auto dataIterator = data.cbegin();
    char dataBuffer[3];
    char printableBuffer[BYTES_PER_LINE + 1];
    bzero(printableBuffer, sizeof(printableBuffer));

    for (int i = 0; i < BYTES_PER_LINE; ++i)
    {
        if (dataIterator != data.cend())
        {
            bzero(dataBuffer, sizeof(dataBuffer));
            snprintf(dataBuffer, sizeof(dataBuffer), "%02x", *dataIterator & 0xff);

            if ((*dataIterator >= 32) && (*dataIterator < 127))
            {
                printableBuffer[i] = *dataIterator;
            }
            else
            {
                printableBuffer[i] = '.';
            }

            stream << dataBuffer << " ";
            ++dataIterator;
        }
        else
        {
            stream << "   ";
        }

        if ((i + 1) % (BYTES_PER_LINE / 2) == 0)
        {
            stream << " ";
        }
    }
    stream << printableBuffer;
}

} /* namespace Glisseo */
