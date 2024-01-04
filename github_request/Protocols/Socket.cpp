#include "Socket.h"

#define LOGGER_INFO(M) \
    std::cout << std::string(PROTOCOL_NAME) << " " << M << " " << std::endl; \

namespace Protocols {
    WebSocket* WebSocket::get_instance() {
        static WebSocket ins;
        return &ins;
    }

    void WebSocket::configure() {
        LOGGER_INFO("Socket configuration");
    }

    void WebSocket::connect() {
        LOGGER_INFO("Connected to socket");
    }

    void WebSocket::bind() {
        LOGGER_INFO("Binding Socket");
    }

    void WebSocket::execute(const std::string& _command) {
        LOGGER_INFO("execute command: " << _command);
    }
};