#ifndef GLISSEO_NETWORK_PROTOCOL_NETSTRINGDECODER_H_
#define GLISSEO_NETWORK_PROTOCOL_NETSTRINGDECODER_H_

#include <string>

namespace Flix {

class NetstringDecoder {
public:
    NetstringDecoder();
    virtual ~NetstringDecoder();

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

} /* namespace Flix */

#endif /* GLISSEO_NETWORK_PROTOCOL_NETSTRINGDECODER_H_ */
