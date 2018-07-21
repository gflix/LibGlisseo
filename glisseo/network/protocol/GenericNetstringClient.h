#ifndef GLISSEO_NETWORK_PROTOCOL_GENERICNETSTRINGCLIENT_H_
#define GLISSEO_NETWORK_PROTOCOL_GENERICNETSTRINGCLIENT_H_

#include <string>
#include <vector>
#include <glisseo/network/protocol/NetstringDecoder.h>
#include <glisseo/network/protocol/Messages.h>
#include <glisseo/network/tcp/TcpClient.h>

namespace Glisseo {

class GenericNetstringClient: public TcpClient {
public:
    GenericNetstringClient(void);
    virtual ~GenericNetstringClient() = default;

    virtual void connect(std::string host, int port) override;

    void sendMessage(const std::string& message) const;
    void receiveMessages(Messages& messages);

private:
    NetstringDecoder netstringDecoder;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_GENERICNETSTRINGCLIENT_H_ */
