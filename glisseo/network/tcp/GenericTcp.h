#ifndef NETWORKING_TCP_GENERICTCP_H_
#define NETWORKING_TCP_GENERICTCP_H_

#include <glisseo/utils/GenericDescriptor.h>

#define TCP_PORT_MIN (1)
#define TCP_PORT_MAX (65535)

namespace Glisseo {

/// Basic class for TCP clients, connections and servers
class GenericTcp: public GenericDescriptor {
public:
    GenericTcp(void);
    virtual ~GenericTcp() = default;

    /// True if the underlying descriptor is valid
    bool isConnected(void) const;

protected:
    // TODO: replace with Glisseo::withinRange()
    /// Deprecated: checks if a value is within a range
    bool withinRange(int value, int min, int max) const;
};

} /* namespace Glisseo */

#endif /* NETWORKING_TCP_GENERICTCP_H_ */
