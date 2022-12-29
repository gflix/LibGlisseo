#include <unistd.h>
#include <memory>
#include <stdexcept>
#include <glisseo/utils/Select.h>
#include <glisseo/network/tcp/GenericTcpConnection.h>

#define SOCKET_READ_TIMEOUT_MICROSECS (100000)
#define SOCKET_WRITE_TIMEOUT_MICROSECS (100000)

namespace Glisseo {

GenericTcpConnection::GenericTcpConnection()
{
}

void GenericTcpConnection::disconnect(void)
{
    if (isConnected())
    {
        ::close(descriptor);
        invalidateDescriptor();
    }
}

void GenericTcpConnection::send(const std::string& data) const
{
    if (!isConnected())
    {
        throw std::runtime_error("not connected");
    }

    Select select;
    select.addWriteDescriptor(descriptor);
    select.setTimeout(0, SOCKET_WRITE_TIMEOUT_MICROSECS);

    if (select.execute() <= 0)
    {
        throw std::runtime_error("could not write to socket");
    }

    size_t dataSize = data.size();
    ssize_t bytesWritten = write(descriptor, data.c_str(), data.size());

    if ((ssize_t) dataSize != bytesWritten)
    {
        throw std::runtime_error("could not write to socket");
    }
}

void GenericTcpConnection::receive(std::string& data, size_t bufferSize) const
{
    if (!isConnected())
    {
        throw std::runtime_error("not connected");
    }

    Select select;
    select.addReadDescriptor(descriptor);
    select.setTimeout(0, SOCKET_READ_TIMEOUT_MICROSECS);

    if (select.execute() <= 0)
    {
        throw std::runtime_error("read from socket timed out");
    }

    std::unique_ptr<char> buffer { new char[bufferSize] };
    ssize_t bytesRead = read(descriptor, buffer.get(), bufferSize);

    data = std::move(std::string(buffer.get(), bytesRead));
}

} /* namespace Glisseo */
