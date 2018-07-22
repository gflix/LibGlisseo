#ifndef GLISSEO_NETWORK_PROTOCOL_GENERICSERVERCONNECTION_H_
#define GLISSEO_NETWORK_PROTOCOL_GENERICSERVERCONNECTION_H_

#include <glisseo/utils/GenericThread.h>

namespace Glisseo {

/// Basic class for server connections
class GenericServerConnection: public GenericThread {
public:
    /// Initializes the server connection with an identifier, a retrieved POSIX descriptor and a peer address
    GenericServerConnection(
        const std::string& identifier,
        int descriptor,
        const std::string& peer);
    virtual ~GenericServerConnection() = default;

    /// Close the connection
    void closeConnection(void);
    /// Send a message through the connection
    virtual void send(const std::string& message);

    /// Retrieves the peer address
    const std::string& getPeer(void) const;

protected:
    /// POSIX descriptor of the connection
    int descriptor;
    /// Address of the peer
    std::string peer;

    /// Overriden method to add the stored descriptor to the Select instance
    virtual void updateDescriptors(Select& select) override;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_GENERICSERVERCONNECTION_H_ */
