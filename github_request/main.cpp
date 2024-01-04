#include <iostream>
#include "Socket.h"

using namespace Protocols;

int main() {
    std::cout << "Hello World!" << std::endl;
    Socket* m_socket = WebSocket::get_instance();
    m_socket->configure();
    m_socket->connect();
    m_socket->bind();
    m_socket->execute("Hello World");
    return 0;
}