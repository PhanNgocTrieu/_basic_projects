#ifndef _HTTP_PROTOCOL_H_
#define _HTTP_PROTOCOL_H_

namespace Protocols {
    class HttpRequest {
        public:
            static HttpRequest* get_instance();
            void download();
            void post();
    };

};

#endif /* _HTTP_PROTOCOL_H_ */