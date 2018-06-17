#include <iostream>
#include <glisseo/utils/Select.h>
#include <glisseo/utils/Timer.h>

using namespace std;

ostream& printTimestamp(ostream& stream)
{
    timespec currentTime;
    clock_gettime(CLOCK_MONOTONIC, &currentTime);

    char buffer[32];

    snprintf(buffer, sizeof(buffer) - 1, "%8ld.%03d", currentTime.tv_sec, currentTime.tv_nsec / 1000000);

    stream << buffer;

    return stream;
}

int main(int argc, char* argv[])
{

    Flix::Select timerSelect;
    Flix::Timer timerA;
    Flix::Timer timerB;

    timerA.setInterval({2, 0});
    timerB.setInterval({0, 400000000});

    cout << printTimestamp << " -> starting the timers" << endl;

    timerA.start();
    timerB.start();
    timerSelect.addReadDescriptor(timerA.getDescriptor());
    timerSelect.addReadDescriptor(timerB.getDescriptor());

    int counter = 20;

    while (--counter > 0)
    {
        try
        {
            timerSelect.execute();
        }
        catch (exception& e)
        {
            cout << "ERROR: select() returned an error (" << e.what() << ")! Skipping." << endl;
        }

        if (timerSelect.readDescriptorIsSet(timerA.getDescriptor()))
        {
            cout << printTimestamp << " -> timerA fired an event (" << timerA.getExpirationCount() << ", " << counter << ")" << endl;
        }
        if (timerB.isRunning())
        {
            if (timerSelect.readDescriptorIsSet(timerB.getDescriptor()))
            {
                cout << printTimestamp << " -> timerB fired an event (" << timerB.getExpirationCount() << ", " << counter << ")" << endl;
                if (counter < 5)
                {
                    cout << printTimestamp << " -> timerB stopped." << endl;
                    timerSelect.removeReadDescriptor(timerB.getDescriptor());
                    timerB.stop();
                }
            }
        }
    }

    return 0;
}
