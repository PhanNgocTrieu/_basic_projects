#include "HTTP.h"

namespace Protocols {
    HttpRequest* HttpRequest::get_instance() {
        static HttpRequest _ins;
        return &_ins;
    }

    void HttpRequest::download() {

    }
    void HttpRequest::post() {

    }
};