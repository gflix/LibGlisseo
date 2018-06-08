#ifndef GLISSEO_NETWORK_PROTOCOL_GENERICJSONOVERNETSTRINGCLIENT_H_
#define GLISSEO_NETWORK_PROTOCOL_GENERICJSONOVERNETSTRINGCLIENT_H_

#include <glisseo/network/protocol/GenericNetstringClient.h>
#include <glisseo/network/protocol/Messages.h>

namespace Flix {

class GenericJsonOverNetstringClient: public GenericNetstringClient {
public:
    GenericJsonOverNetstringClient();
    virtual ~GenericJsonOverNetstringClient();

    void sendJsonMessage(const Json::Value& jsonMessage) const;
    void receiveJsonMessages(JsonMessages& jsonMessages);
};

} /* namespace Flix */

#endif /* GLISSEO_NETWORK_PROTOCOL_GENERICJSONOVERNETSTRINGCLIENT_H_ */
