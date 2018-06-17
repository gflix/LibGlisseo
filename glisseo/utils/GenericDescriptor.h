#ifndef GLISSEO_UTILS_GENERICDESCRIPTOR_H_
#define GLISSEO_UTILS_GENERICDESCRIPTOR_H_

#define INVALID_DESCRIPTOR (-1)

namespace Flix {

class GenericDescriptor {
public:
    GenericDescriptor();
    virtual ~GenericDescriptor();

    int getDescriptor(void) const;

protected:
    int descriptor;

    bool descriptorIsValid(void) const;
    void invalidateDescriptor(void);
};

} /* namespace Flix */

#endif /* GLISSEO_UTILS_GENERICDESCRIPTOR_H_ */
