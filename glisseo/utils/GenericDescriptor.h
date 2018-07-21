#ifndef GLISSEO_UTILS_GENERICDESCRIPTOR_H_
#define GLISSEO_UTILS_GENERICDESCRIPTOR_H_

#define INVALID_DESCRIPTOR (-1)

namespace Glisseo {

class GenericDescriptor {
public:
    GenericDescriptor(void);
    virtual ~GenericDescriptor() = default;

    int getDescriptor(void) const;

protected:
    int descriptor;

    bool descriptorIsValid(void) const;
    void invalidateDescriptor(void);
};

} /* namespace Glisseo */

#endif /* GLISSEO_UTILS_GENERICDESCRIPTOR_H_ */
