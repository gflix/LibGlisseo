#ifndef GLISSEO_NETWORK_PROTOCOL_GENERICJSONOVERNETSTRINGCLIENT_H_
#define GLISSEO_NETWORK_PROTOCOL_GENERICJSONOVERNETSTRINGCLIENT_H_

#include <glisseo/network/protocol/GenericNetstringClient.h>
#include <glisseo/network/protocol/Messages.h>

namespace Glisseo {

class GenericJsonOverNetstringClient: public GenericNetstringClient {
public:
    GenericJsonOverNetstringClient();
    virtual ~GenericJsonOverNetstringClient();

    void sendJsonMessage(const Json::Value& jsonMessage) const;
    void receiveJsonMessages(JsonMessages& jsonMessages);
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_GENERICJSONOVERNETSTRINGCLIENT_H_ */
