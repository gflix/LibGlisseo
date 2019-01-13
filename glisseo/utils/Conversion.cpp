#include <cstring>
#include <stdexcept>
#include <glisseo/utils/Conversion.h>

namespace Glisseo {

const char hexDigits[2][16] = {
    { '0', '1', '2', '3', '4', '5', '6', '7',
      '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'},
    { '0', '1', '2', '3', '4', '5', '6', '7',
      '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'},
};

unsigned char decodeHexDigit(const char& digit);

std::string Conversion::binToHex(const std::string& bin, HexDigitCase hexDigitCase)
{
    return Glisseo::binToHex(bin, hexDigitCase);
}

std::string Conversion::binToHexEscaped(const std::string& bin)
{
    return Glisseo::binToHexEscaped(bin);
}

std::string Conversion::binToAscii(const std::string& bin)
{
    return Glisseo::binToAscii(bin);
}

std::string Conversion::hexToBin(const std::string& hex)
{
    return Glisseo::hexToBin(hex);
}

std::string Conversion::reverse(const std::string& text)
{
    return Glisseo::reverse(text);
}

unsigned long long Conversion::binToUnsigned(const std::string& bin)
{
    return Glisseo::binToUnsignedLe(bin);
}

unsigned long long Conversion::binToUnsigned(char character)
{
    return Glisseo::binToUnsigned(character);
}

signed long long Conversion::binToSigned(const std::string& bin)
{
    return Glisseo::binToSignedLe(bin);
}

signed long long Conversion::binToSigned(char character)
{
    return Glisseo::binToSigned(character);
}

std::string Conversion::unsignedToBin(unsigned long long value, int digits)
{
    return Glisseo::unsignedToBinLe(value, digits);
}

std::string Conversion::unsignedCharToBin(unsigned long long value)
{
    return Glisseo::unsignedCharToBin(value);
}

std::string Conversion::unsignedShortToBin(unsigned long long value)
{
    return Glisseo::unsignedShortToBinLe(value);
}

std::string Conversion::unsignedCharToHex(unsigned int value)
{
    return Glisseo::unsignedCharToHex(value);
}

std::string Conversion::unsignedShortToHex(unsigned int value)
{
    return Glisseo::unsignedShortToHex(value);
}

std::string binToHex(const std::string& bin, HexDigitCase hexDigitCase)
{
    std::string hex;

    int hexDigitSet;
    switch (hexDigitCase)
    {
    case HexDigitCase::LOWER:
        hexDigitSet = 0;
        break;
    case HexDigitCase::UPPER:
        hexDigitSet = 1;
        break;
    default:
        throw std::invalid_argument("invalid argument for hexDigitCase");
    }

    for (auto& element: bin)
    {
        hex += hexDigits[hexDigitSet][(element >> 4) & 0x0f];
        hex += hexDigits[hexDigitSet][element & 0x0f];
    }

    return hex;
}

std::string binToHexEscaped(const std::string& bin)
{
    std::string hex;

    for (auto& element: bin)
    {
        hex += "\\x";
        hex += hexDigits[0][(element >> 4) & 0x0f];
        hex += hexDigits[0][element & 0x0f];
    }

    return hex;
}

std::string binToAscii(const std::string& bin)
{
    std::string ascii;

    for (auto& element: bin)
    {
        int value = static_cast<unsigned char>(element);
        if (value >= 32 && value < 127)
        {
            ascii += element;
        }
        else
        {
            ascii += '.';
        }
    }

    return ascii;
}

std::string hexToBin(const std::string& hex)
{
    if (hex.size() % 2)
    {
        throw std::invalid_argument("invalid character count in input");
    }

    std::string bin;

    auto iterator = hex.cbegin();

    while (iterator != hex.cend())
    {
        unsigned char byte;

        byte = decodeHexDigit(*iterator) << 4;
        ++iterator;
        byte |= decodeHexDigit(*iterator);
        ++iterator;

        bin += byte;
    }

    return bin;
}

std::string reverse(const std::string& text)
{
    std::string reversedText;

    for (auto it = text.crbegin(); it != text.crend(); ++it)
    {
        reversedText += *it;
    }

    return reversedText;
}

unsigned long long binToUnsigned(char character)
{
    return binToUnsignedLe(std::string(1, character));
}

unsigned long long binToUnsignedLe(const std::string& bin)
{
    if (bin.size() > 8)
    {
        throw std::invalid_argument("too much input");
    }

    unsigned long long value = 0;
    for (auto it = bin.crbegin(); it != bin.crend(); ++it)
    {
        unsigned char characterValue = static_cast<unsigned char>(*it);

        value = (value << 8) | characterValue;
    }

    return value;
}

unsigned long long binToUnsignedBe(const std::string& bin)
{
    return binToUnsignedLe(reverse(bin));
}

signed long long binToSigned(char character)
{
    return binToSignedLe(std::string(1, character));
}

signed long long binToSignedLe(const std::string& bin)
{
    std::string paddedBin { bin };

    if (!paddedBin.empty())
    {
        // if the most significant bit is set, pad the input with 0xff until its 8 bytes long
        if (static_cast<unsigned char>(paddedBin[paddedBin.size() - 1]) & 0x80)
        {
            while (paddedBin.size() < 8)
            {
                paddedBin += '\xff';
            }
        }
    }

    return static_cast<signed long long>(binToUnsignedLe(paddedBin));
}

signed long long binToSignedBe(const std::string& bin)
{
    return binToSignedLe(reverse(bin));
}

std::string unsignedToBinLe(unsigned long long value, int digits)
{
    std::string bin;

    for (; digits > 0; --digits)
    {
        bin.push_back(value & 0xff);
        value >>= 8;
    }

    return bin;
}

std::string unsignedCharToBin(unsigned long long value)
{
    return unsignedToBinLe(value, 1);
}

std::string unsignedShortToBinLe(unsigned long long value)
{
    return unsignedToBinLe(value, 2);
}

std::string unsignedCharToHex(unsigned int value)
{
    value &= 0xff;
    char buffer[4];

    bzero(buffer, sizeof(buffer));
    snprintf(buffer,sizeof(buffer), "%02x", value);

    return buffer;
}

std::string unsignedShortToHex(unsigned int value)
{
    value &= 0xffff;
    char buffer[6];

    bzero(buffer, sizeof(buffer));
    snprintf(buffer,sizeof(buffer), "%04x", value);

    return buffer;
}

unsigned char decodeHexDigit(const char& digit)
{
    if (digit >= '0' && digit <= '9')
    {
        return digit - '0';
    }
    else if (digit >= 'A' && digit <= 'F')
    {
        return digit - 'A' + 10;
    }
    else if (digit >= 'a' && digit <= 'f')
    {
        return digit - 'a' + 10;
    }
    throw std::invalid_argument("invalid hex digit");
}

} /* namespace Glisseo */
