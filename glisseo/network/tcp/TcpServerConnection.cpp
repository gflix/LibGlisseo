#include <glisseo/network/tcp/TcpServerConnection.h>

namespace Glisseo {

TcpServerConnection::TcpServerConnection(int descriptor):
    GenericTcpConnection()
{
    this->descriptor = descriptor;
}

} /* namespace Glisseo */
