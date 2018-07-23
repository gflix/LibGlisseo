#ifndef NETWORKING_DIGEST_SHA1_H_
#define NETWORKING_DIGEST_SHA1_H_

#include <string>

namespace Glisseo {

/// Implementation of the SHA1 hashing algorithm
class Sha1 {
public:
    Sha1(void);
    virtual ~Sha1() = default;

    /// Append data to the internal buffer
    void appendMessage(const std::string& message);
    /// Retrieve the content of the internal buffer
    const std::string& getMessage(void) const;

    /// Reset the internal buffer
    void reset(void);

    /// Calculate the SHA1 digest from the internal buffer
    std::string getHash(void) const;

private:
    std::string message;
};

} /* namespace Glisseo */

#endif /* NETWORKING_DIGEST_SHA1_H_ */
