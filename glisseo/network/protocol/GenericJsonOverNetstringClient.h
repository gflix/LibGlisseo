#ifndef GLISSEO_NETWORK_PROTOCOL_GENERICJSONOVERNETSTRINGCLIENT_H_
#define GLISSEO_NETWORK_PROTOCOL_GENERICJSONOVERNETSTRINGCLIENT_H_

#include <glisseo/network/protocol/GenericNetstringClient.h>
#include <glisseo/network/protocol/Messages.h>

namespace Glisseo {

/// Basic class of a TCP client which transports JSON encoded messages using netstrings
class GenericJsonOverNetstringClient: public GenericNetstringClient {
public:
    GenericJsonOverNetstringClient(void);
    virtual ~GenericJsonOverNetstringClient() = default;

    /// Send a JSON message through the client connection
    void sendJsonMessage(const Json::Value& jsonMessage) const;
    /// Receive a JSON message from the server
    void receiveJsonMessages(JsonMessages& jsonMessages);
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_GENERICJSONOVERNETSTRINGCLIENT_H_ */
