#ifndef NETWORKING_CONVERSION_H_
#define NETWORKING_CONVERSION_H_

#include <string>

namespace Glisseo {

enum class HexDigitCase {
    LOWER,
    UPPER,
};

/// Static methods for converting between different formats
class Conversion {
public:
    /// Convert a binary message to hexadecimal
    [[deprecated]]
    static std::string binToHex(
        const std::string& bin,
        HexDigitCase hexDigitCase = HexDigitCase::LOWER);
    /// Convert a binary message to an escaped hexadecimal string which could be used in C code
    [[deprecated]]
    static std::string binToHexEscaped(const std::string& bin);
    /// Converts a binary message to an ASCII string where unprintable characters are replaced with a dot '.'
    [[deprecated]]
    static std::string binToAscii(const std::string& bin);
    /// Converts a hexadecimal string back to a binary message
    [[deprecated]]
    static std::string hexToBin(const std::string& hex);
    /// Reverse a string
    [[deprecated]]
    static std::string reverse(const std::string& text);

    /// Converts a binary message to a unsigned number
    [[deprecated]]
    static unsigned long long binToUnsigned(const std::string& bin);
    /// Converts a character to a unsigned number
    [[deprecated]]
    static unsigned long long binToUnsigned(char character);
    /// Converts a binary message to a signed number
    [[deprecated]]
    static signed long long binToSigned(const std::string& bin);
    /// Converts a character to a signed number
    [[deprecated]]
    static signed long long binToSigned(char character);

    /// Converts a unsigned number to a binary message with a given length in bytes
    [[deprecated]]
    static std::string unsignedToBin(unsigned long long value, int digits);
    /// Converts a unsigned character (8 bit) to a binary message
    [[deprecated]]
    static std::string unsignedCharToBin(unsigned long long value);
    /// Converts a unsigned short (16 bit) to a binary message
    [[deprecated]]
    static std::string unsignedShortToBin(unsigned long long value);

    /// Converts a unsigned character (8 bit) to a hex string with leading zeroes
    [[deprecated]]
    static std::string unsignedCharToHex(unsigned int value);
    /// Converts a unsigned short (16 bit) to a hex string with leading zeroes
    [[deprecated]]
    static std::string unsignedShortToHex(unsigned int value);
};

std::string binToHex(
    const std::string& bin,
    HexDigitCase hexDigitCase = HexDigitCase::LOWER);
std::string binToHexEscaped(const std::string& bin);
std::string binToAscii(const std::string& bin);
std::string hexToBin(const std::string& hex);
std::string reverse(const std::string& text);

unsigned long long binToUnsigned(char character);
unsigned long long binToUnsignedLe(const std::string& bin);
unsigned long long binToUnsignedBe(const std::string& bin);
signed long long binToSigned(char character);
signed long long binToSignedLe(const std::string& bin);
signed long long binToSignedBe(const std::string& bin);

std::string unsignedToBinLe(unsigned long long value, int digits);
std::string unsignedCharToBin(unsigned long long value);
std::string unsignedShortToBinLe(unsigned long long value);
std::string unsignedCharToHex(unsigned int value);
std::string unsignedShortToHex(unsigned int value);

} /* namespace Glisseo */

#endif /* NETWORKING_CONVERSION_H_ */
