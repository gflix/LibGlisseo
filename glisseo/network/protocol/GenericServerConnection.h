#ifndef GLISSEO_NETWORK_PROTOCOL_GENERICSERVERCONNECTION_H_
#define GLISSEO_NETWORK_PROTOCOL_GENERICSERVERCONNECTION_H_

#include <glisseo/utils/GenericThread.h>

namespace Glisseo {

class GenericServerConnection: public GenericThread {
public:
    GenericServerConnection(
        const std::string& identifier,
        int descriptor,
        const std::string& peer);
    virtual ~GenericServerConnection() = default;

    void closeConnection(void);
    virtual void send(const std::string& message);

    const std::string& getPeer(void) const;

protected:
    int descriptor;
    std::string peer;

    virtual void updateDescriptors(Select& select) override;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_GENERICSERVERCONNECTION_H_ */
