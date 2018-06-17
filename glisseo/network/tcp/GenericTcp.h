#ifndef NETWORKING_TCP_GENERICTCP_H_
#define NETWORKING_TCP_GENERICTCP_H_

#include <glisseo/utils/GenericDescriptor.h>

#define TCP_PORT_MIN (1)
#define TCP_PORT_MAX (65535)

namespace Flix {

class GenericTcp: public GenericDescriptor {
public:
    GenericTcp();
    virtual ~GenericTcp();

    bool isConnected(void) const;

protected:
    bool withinRange(int value, int min, int max) const;
};

} /* namespace Flix */

#endif /* NETWORKING_TCP_GENERICTCP_H_ */
