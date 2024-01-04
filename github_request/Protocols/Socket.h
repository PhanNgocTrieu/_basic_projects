#ifndef __SOCKET_H__
#define __SOCKET_H__

inline const int PORT = 8080;
inline const char* SERVER = "socket.io";
inline const char* PROTOCOL_NAME = "Socket";

#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>


namespace Protocols {
    class Socket {
        public:
            virtual void configure() = 0;
            virtual void bind() = 0;
            virtual void connect() = 0;
            virtual void execute(const std::string& _command) = 0;

        protected:
            struct sockaddr_in server_addr;
            struct hostent *he;
    };

    class WebSocket : public Socket {
        public:
            static WebSocket* get_instance();
            void configure() override;
            void bind() override;
            void connect() override;
            void execute(const std::string& _command) override;
    };
};

#endif /* __SOCKET_H__ */