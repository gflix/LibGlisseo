#ifndef GLISSEO_UTILS_GENERICDESCRIPTOR_H_
#define GLISSEO_UTILS_GENERICDESCRIPTOR_H_

#define INVALID_DESCRIPTOR (-1)

namespace Glisseo {

/// Basic class which encapsulates a POSIX descriptor, i.e. files and sockets
class GenericDescriptor {
public:
    GenericDescriptor(void);
    virtual ~GenericDescriptor() = default;

    /// Retrieves the stored descriptor
    int getDescriptor(void) const;

protected:
    /// POSIX descriptor
    int descriptor;

    /// True if the stored descriptor has a positive non-zero value
    bool descriptorIsValid(void) const;
    /// Reset descriptor to be invalid
    void invalidateDescriptor(void);
};

} /* namespace Glisseo */

#endif /* GLISSEO_UTILS_GENERICDESCRIPTOR_H_ */
