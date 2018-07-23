#ifndef GLISSEO_NETWORK_PROTOCOL_NETSTRINGDECODER_H_
#define GLISSEO_NETWORK_PROTOCOL_NETSTRINGDECODER_H_

#include <string>

namespace Glisseo {

/// Implementation of the decoder for Netstrings
class NetstringDecoder {
public:
    NetstringDecoder();
    virtual ~NetstringDecoder() = default;

    /// Append data to the internal buffer
    void appendText(const std::string& text);
    /// Checks the internal buffer for the presence of a valid netstring and stores its parameters for further processing
    void checkBuffer(void);
    /// True if the internal buffer has a message
    bool hasMessage(void);
    /// Extract the first message from the buffer
    std::string getMessage(void);

    /// Reset the internal buffer
    void resetBuffer(void);
    /// Retrieve the content of the internal buffer
    const std::string& getBuffer(void) const;

private:
    std::string buffer;

    std::string::size_type colonPosition;
    int messageLength;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_NETSTRINGDECODER_H_ */
