#ifndef NETWORKING_CONVERSION_H_
#define NETWORKING_CONVERSION_H_

#include <string>

namespace Glisseo {

enum class HexDigitCase {
    LOWER,
    UPPER,
};

class Conversion {
public:
    static std::string binToHex(
        const std::string& bin,
        HexDigitCase hexDigitCase = HexDigitCase::LOWER);
    static std::string binToHexEscaped(const std::string& bin);
    static std::string binToAscii(const std::string& bin);
    static std::string hexToBin(const std::string& hex);
    static std::string reverse(const std::string& text);

    static unsigned long long binToUnsigned(const std::string& bin);
    static unsigned long long binToUnsigned(char character);
    static signed long long binToSigned(const std::string& bin);
    static signed long long binToSigned(char character);

    static std::string unsignedToBin(unsigned long long value, int digits);
    static std::string unsignedCharToBin(unsigned long long value);
    static std::string unsignedShortToBin(unsigned long long value);

private:
    static unsigned char decodeHexDigit(const char& digit);
};

} /* namespace Glisseo */

#endif /* NETWORKING_CONVERSION_H_ */
