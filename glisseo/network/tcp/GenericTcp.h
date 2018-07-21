#ifndef NETWORKING_TCP_GENERICTCP_H_
#define NETWORKING_TCP_GENERICTCP_H_

#include <glisseo/utils/GenericDescriptor.h>

#define TCP_PORT_MIN (1)
#define TCP_PORT_MAX (65535)

namespace Glisseo {

class GenericTcp: public GenericDescriptor {
public:
    GenericTcp(void);
    virtual ~GenericTcp() = default;

    bool isConnected(void) const;

protected:
    bool withinRange(int value, int min, int max) const;
};

} /* namespace Glisseo */

#endif /* NETWORKING_TCP_GENERICTCP_H_ */
