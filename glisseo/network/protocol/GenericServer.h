#ifndef GLISSEO_NETWORK_PROTOCOL_GENERICSERVER_H_
#define GLISSEO_NETWORK_PROTOCOL_GENERICSERVER_H_

#include <arpa/inet.h>
#include <cstring>
#include <mutex>
#include <vector>
#include <glisseo/utils/GenericThread.h>
#include <glisseo/utils/Log.h>
#include <glisseo/network/tcp/TcpServer.h>

namespace Glisseo {

/// Basic template for TCP servers
template<typename T>
class GenericServer: public GenericThread {
public:
    /// Initializes the server with an identifier, a TCP server port and the preferred protocol (IPv4/IPv6)
    GenericServer(const std::string& identifier, int port, Protocol protocol = Protocol::IPV4):
        GenericThread(identifier),
        port(port),
        protocol(protocol)
    {
    }
    virtual ~GenericServer()
    {
    }

protected:
    /// TCP port number
    int port;
    /// Chosen protocol (IPv4/IPv6)
    Protocol protocol;
    /// Instance of the TCP server
    TcpServer tcpServer;
    /// Mutex to retrieve exclusive access to the connectionThreads;
    std::mutex connectionThreadsMutex;
    /// List of active connection threads
    std::vector<T*> connectionThreads;

    /// Overriden thread setup method
    virtual bool setup(void) override
    {
        try
        {
            tcpServer.start(port, protocol);
        }
        catch (std::exception& e)
        {
            LOG_ERROR("Could not start server \"" << identifier << "\" on port " << port << " (" << e.what() << ")");
            return false;
        }
        return true;
    }

    bool periodicTask(void) override
    {
        cleanupClosedClientConnections();

        return true;
    }

    /// Templated wrapper to manage active and new client connections
    template<typename U>
    void manageClientConnections(const Select& select, U newConnectionThread)
    {
        if (!select.readDescriptorIsSet(tcpServer.getDescriptor()))
        {
            return;
        }

        T* connectionThread = nullptr;
        if (protocol == Protocol::IPV4)
        {
            sockaddr_in clientAddress;
            unsigned int clientAddressSize = sizeof(clientAddress);
            int clientDescriptor = accept(tcpServer.getDescriptor(), (sockaddr*) &clientAddress, &clientAddressSize);
            if (clientDescriptor >= 0)
            {
                char clientIpAddressBuffer[INET_ADDRSTRLEN];
                bzero(clientIpAddressBuffer, sizeof(clientIpAddressBuffer));
                inet_ntop(AF_INET, &clientAddress.sin_addr, clientIpAddressBuffer, sizeof(clientIpAddressBuffer));
                std::string peer =
                    std::string(clientIpAddressBuffer) + ':' + std::to_string(ntohs(clientAddress.sin_port));

                connectionThread = newConnectionThread(clientDescriptor, peer);
            }
        }
        else if (protocol == Protocol::IPV6)
        {
            sockaddr_in6 clientAddress;
            unsigned int clientAddressSize = sizeof(clientAddress);
            int clientDescriptor = accept(tcpServer.getDescriptor(), (sockaddr*) &clientAddress, &clientAddressSize);
            if (clientDescriptor >= 0)
            {
                char clientIpAddressBuffer[INET6_ADDRSTRLEN];
                bzero(clientIpAddressBuffer, sizeof(clientIpAddressBuffer));
                inet_ntop(AF_INET6, &clientAddress.sin6_addr, clientIpAddressBuffer, sizeof(clientIpAddressBuffer));
                std::string peer =
                    std::string(clientIpAddressBuffer) + ':' + std::to_string(ntohs(clientAddress.sin6_port));

                connectionThread = newConnectionThread(clientDescriptor, peer);
            }
        }

        if (connectionThread && connectionThread->start()) {
            std::lock_guard<std::mutex> lock(connectionThreadsMutex);
            connectionThreads.push_back(connectionThread);
        }

        cleanupClosedClientConnections();
    }

    virtual void cleanupClosedClientConnections(void)
    {
        std::lock_guard<std::mutex> lock(connectionThreadsMutex);

        auto checkConnectionThread = connectionThreads.begin();
        while (checkConnectionThread != connectionThreads.end()) {
            if (!(*checkConnectionThread)) {
                checkConnectionThread = connectionThreads.erase(checkConnectionThread);
                continue;
            }
            if ((*checkConnectionThread)->threadHasFinished()) {
                (*checkConnectionThread)->stop();
                delete *checkConnectionThread;
                checkConnectionThread = connectionThreads.erase(checkConnectionThread);
                continue;
            }
            ++checkConnectionThread;
        }
    }

    /// Overriden method to add the TCP server descriptor to the Select instance
    void updateDescriptors(Select& select) override
    {
        select.addReadDescriptor(tcpServer.getDescriptor());
    }
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_GENERICSERVER_H_ */
