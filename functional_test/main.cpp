#include <thread>
#include <pthread.h>
#include <iostream>
#include <time.h>
#include <unistd.h>

class ThreadHandler {
    public:
        void startThread() {
            std::thread _th([this](){
                do {
                    if (this->getValue() != 0) {
                        std::cout << "break; " << std::flush << std::endl;
                        break;
                    }
                    usleep(500000);
                    std::cout << " current thread called - value: " << this->getValue() << std::flush << std::endl;
                } while(this->getValue() == 0);

                std::cout << "outside; " << std::flush << std::endl;
            });

            _th.detach();
        }

        int getValue() const {
            return _value;
        }

        void setValue(int value) {
            _value = value;
            std::cout << "setValue: " << _value << std::flush << std::endl;
        };
    protected:
        int _value{0};
};

int main() {
    ThreadHandler* m_handler = new ThreadHandler();

    m_handler->startThread();

    sleep(3.5);

    m_handler->setValue(21);
    // scanf("\n");

    if (m_handler) {
        delete m_handler;
    }
}