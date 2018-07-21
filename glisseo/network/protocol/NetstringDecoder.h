#ifndef GLISSEO_NETWORK_PROTOCOL_NETSTRINGDECODER_H_
#define GLISSEO_NETWORK_PROTOCOL_NETSTRINGDECODER_H_

#include <string>

namespace Glisseo {

class NetstringDecoder {
public:
    NetstringDecoder();
    virtual ~NetstringDecoder() = default;

    void appendText(const std::string& text);
    void checkBuffer(void);
    bool hasMessage(void);
    std::string getMessage(void);

    void resetBuffer(void);
    const std::string& getBuffer(void) const;

private:
    std::string buffer;

    std::string::size_type colonPosition;
    int messageLength;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_NETSTRINGDECODER_H_ */
