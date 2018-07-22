#ifndef SRC_GENERICTHREAD_H_
#define SRC_GENERICTHREAD_H_

#include <thread>
#include <glisseo/utils/Select.h>

#define CONTROL_PIPE_OUT (1)
#define CONTROL_PIPE_IN (0)

namespace Glisseo {

enum class ThreadControl {
    UNKNOWN,
    QUIT,
    TASK
};

/// Encapsulates a generic thread framework
class GenericThread {
public:
    /// Initializes a new thread with a given identifier, optionally the thread will not print log output
    GenericThread(const std::string& identifier, bool silent = false);
    virtual ~GenericThread();

    /// Starts the thread
    bool start(void);
    /// Sends an internal signal to stop the thread and wait for completion
    bool stop(void);
    /// Sends an internal signal to run the thread task immediately
    bool runTask(void);

    /// True if the thread has finished its work
    bool threadHasFinished(void) const;

protected:
    /// Identifier of the thread
    std::string identifier;
    /// True if no log output shall be printed
    bool silent;
    /// Internal pipe for sending and receiving signals
    int controlPipe[2];
    /// True if the thread has finished its work
    bool threadFinished;
    /// Pointer to the raw thread instance
    std::thread* genericThread;
    /// Number of seconds between calls to the periodic task
    int periodicTaskInterval;

    /// Method is called before starting the thread to setup the thread
    virtual bool setup(void) = 0;
    /// Method which is called when at least one of the reported descriptors were selected
    virtual bool task(const Select& select) = 0;
    /// Periodically called method for i.e. clean up tasks
    virtual bool periodicTask(void);
    /// Provide information about the owned descriptors and store them within the Select instance
    virtual void updateDescriptors(Select& select);
    /// Sets the interval for the periodic task
    void setPeriodicTaskInterval(int seconds);

    /// Retrieves the maximum out of two numbers
    int max(int a, int b) const;

private:
    void sendSignal(ThreadControl threadControl);
    virtual void run(void);
};

} /* namespace Glisseo */

#endif /* SRC_GENERICTHREAD_H_ */
