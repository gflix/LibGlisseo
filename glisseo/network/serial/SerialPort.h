#ifndef NETWORKING_SERIAL_SERIALPORT_H_
#define NETWORKING_SERIAL_SERIALPORT_H_

#include <string>
#include <glisseo/utils/GenericDescriptor.h>
#include <glisseo/network/serial/Baudrate.h>

#define SERIAL_RECEIVE_BUFFER_SIZE_DEFAULT (128)

namespace Glisseo {

/// Implementation of a serial port (i.e. RS-232)
class SerialPort: public GenericDescriptor {
public:
    SerialPort(void);
    virtual ~SerialPort();

    /// Open a given device at a given baudrate, always use 8N1
    void open(const std::string& device, Baudrate baudrate);
    /// Close the serial port
    void close(void);

    /// Send a message to the serial port
    void send(const std::string& data) const;
    /// Receive a message from the serial port
    void receive(std::string& data, size_t bufferSize = SERIAL_RECEIVE_BUFFER_SIZE_DEFAULT) const;

    /// True if the serial port is opened
    bool isOpened(void) const;
};

} /* namespace Glisseo */

#endif /* NETWORKING_SERIAL_SERIALPORT_H_ */
