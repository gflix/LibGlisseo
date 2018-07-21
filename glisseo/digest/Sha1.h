#ifndef NETWORKING_DIGEST_SHA1_H_
#define NETWORKING_DIGEST_SHA1_H_

#include <string>

namespace Glisseo {

class Sha1 {
public:
    Sha1(void);
    virtual ~Sha1() = default;

    void appendMessage(const std::string& message);
    const std::string& getMessage(void) const;

    void reset(void);

    std::string getHash(void) const;

private:
    std::string message;
};

} /* namespace Glisseo */

#endif /* NETWORKING_DIGEST_SHA1_H_ */
