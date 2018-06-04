#ifndef GLISSEO_NETWORK_PROTOCOL_GENERICJSONOVERNETSTRINGSERVERCONNECTION_H_
#define GLISSEO_NETWORK_PROTOCOL_GENERICJSONOVERNETSTRINGSERVERCONNECTION_H_

#include <json/json.h>
#include <glisseo/network/protocol/GenericNetstringServerConnection.h>

namespace Flix {

class GenericJsonOverNetstringServerConnection: public GenericNetstringServerConnection {
public:
    GenericJsonOverNetstringServerConnection(
        const std::string& identifier,
        int descriptor,
        const std::string& peer);
    virtual ~GenericJsonOverNetstringServerConnection();

    virtual void send(const Json::Value& message);

protected:
    virtual void processMessage(const std::string& message) override;
    virtual void processMessage(const Json::Value& message) = 0;
};

} /* namespace Flix */

#endif /* GLISSEO_NETWORK_PROTOCOL_GENERICJSONOVERNETSTRINGSERVERCONNECTION_H_ */
