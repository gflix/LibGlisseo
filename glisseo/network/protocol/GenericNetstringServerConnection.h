#ifndef GLISSEO_NETWORK_PROTOCOL_GENERICNETSTRINGSERVERCONNECTION_H_
#define GLISSEO_NETWORK_PROTOCOL_GENERICNETSTRINGSERVERCONNECTION_H_

#include <glisseo/network/protocol/GenericServerConnection.h>
#include <glisseo/network/protocol/NetstringDecoder.h>

namespace Glisseo {

class GenericNetstringServerConnection: public GenericServerConnection {
public:
    GenericNetstringServerConnection(
        const std::string& identifier,
        int descriptor,
        const std::string& peer);
    virtual ~GenericNetstringServerConnection();

    virtual void send(const std::string& message) override;

protected:
    virtual bool setup(void) override;
    virtual bool task(const Select& select) override;

    virtual void processMessage(const std::string& message) = 0;

private:
    NetstringDecoder netstringDecoder;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_GENERICNETSTRINGSERVERCONNECTION_H_ */
