#ifndef NETWORKING_SELECT_H_
#define NETWORKING_SELECT_H_

#include <unistd.h>
#include <set>
#include <string>

namespace Glisseo {

typedef std::set<int> Descriptors;

/// Wrapper around the select() call
class Select {
public:
    Select(void);
    virtual ~Select() = default;

    /// Run select() with the configured settings and return the number of descriptors which were selected
    int execute(void);

    /// Add a read descriptor to the list of watched descriptors
    void addReadDescriptor(int descriptor);
    /// Remove a read descriptor from the list if watched descriptors
    void removeReadDescriptor(int descriptor);
    /// Add a write descriptor to the list of watched descriptors
    void addWriteDescriptor(int descriptor);
    /// Remove a write descriptor from the list if watched descriptors
    void removeWriteDescriptor(int descriptor);

    /// Get the number of read descriptors associated with an instance
    size_t getReadDescriptorCount(void) const;
    /// Get the number of write descriptors associated with an instance
    size_t getWriteDescriptorCount(void) const;

    /// True if a given read descriptor was selected on last execute()
    bool readDescriptorIsSet(int descriptor) const;
    /// True if a given write descriptor was selected on last execute()
    bool writeDescriptorIsSet(int descriptor) const;

    /// Sets the timeout for next execute()
    void setTimeout(timeval& timeout);
    /// Sets the timeout in seconds for next execute()
    void setTimeout(time_t timeoutSeconds);
    /// Sets the timeout in seconds and microseconds for next execute()
    void setTimeout(time_t timeoutSeconds, useconds_t timeoutMicroseconds);
    /// Retrieves the currently set timeout
    const timeval& getTimeout(void) const;
    /// Retrieves the remaining time from the last execute() call
    const timeval& getRemainingTime(void) const;

    /// Controls whether the timeout shall be reloaded at the beginning of each execute() calls
    void setAutoReloadTimeout(bool enable);
    /// True if the timer shall be reloaded at the beginning of each execute() call
    bool getAutoReloadTimeout(void) const;

    /// Reload the timeout value
    void reloadTimeout(void);

private:
    fd_set selectReadDescriptors;
    fd_set selectWriteDescriptors;
    Descriptors readDescriptors;
    Descriptors writeDescriptors;

    timeval defaultTimeout;
    timeval timeout;
    bool autoReloadTimeout;

    void addDescriptor(Descriptors& descriptors, int descriptor);
    void removeDescriptor(Descriptors& descriptors, int descriptor);
    int max(int a, int b) const;
};

} /* namespace Glisseo */

#endif /* NETWORKING_SELECT_H_ */
