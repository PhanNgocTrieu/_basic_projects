#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <unordered_map>
#include <sstream>

enum Parse_Type {
    WINDOW = 0,
    RECT,
    CIRCLE,
    FONT
};

struct Color {
    int m_red{0};
    int m_green{0};
    int m_blue{0}; 
    Color() {}
    void operator()(const Color& _other) {
        this->m_blue = _other.m_blue;
        this->m_green = _other.m_green;
        this->m_red = _other.m_red;
    }
    Color& operator<<(const Color& _other) {
        this->m_blue = _other.m_blue;
        this->m_green = _other.m_green;
        this->m_red = _other.m_red;
        return *this;
    }
};

struct Ordinate_Properties {
    float m_initX;
    float m_initY;
    float m_speedX;
    float m_speedY;
    float m_width;
    float m_height;
    float m_radius;
    void operator()(const Ordinate_Properties& _other) {
        this->m_initX     = _other.m_initX;
        this->m_initY     = _other.m_initY;
        this->m_speedX    = _other.m_speedX;
        this->m_speedY    = _other.m_speedY;
        this->m_width     = _other.m_width;
        this->m_height    = _other.m_height;
        this->m_radius    = _other.m_radius;
    } 
};

struct Properties {
    int width{0};
    int height{0};
    float scale{0.0};
    Properties() {}
    Properties(const int _width, const int _height, const float _scale = {0.0}) : width(_width), height(_height), scale(_scale) {}
    Properties(const Properties& _other) : width(_other.width), height(_other.height), scale(_other.scale) {}
};

class Object {
    public:
        virtual Object* genetate_object(const std::vector<std::string>& properties) = 0;
};

class Window: public Object {
    public:
        Window()
        : m_height(0)
        , m_width(0)
        {}
        Window(const int _w, const int _h)
        : m_height(_w)
        , m_width(_h)
        {}

        Object* genetate_object(const std::vector<std::string>& properties) override {
            Window* new_obj = nullptr;
            if (properties.size() == 3) {
                new_obj = new Window(
                    atoi(properties[1].c_str()), 
                    atoi(properties[2].c_str())
                );
            }
            else {
                new_obj = new Window();
            }

            return new_obj;
        }

        void setHeight(const int _h) { m_height = _h; }
        void setWidth(const int _w) { m_width = _w; }
        int getHeight() const { return m_height; }
        int getWidth() const { return m_width; }

        ~Window() {}
    protected:
        int m_height;
        int m_width;
};

class Rectangle : public Object {
        Rectangle() {}
        Rectangle(const Ordinate_Properties& _p, const Color& _cl, const Fonts& _f)
        : m_recProperties(_p), m_color(_cl), m_font(_f) {}
        ~Rectangle() {}

    public:
        Object* genetate_object(const std::vector<std::string>& properties) override {
            // Rectangle* 
            return nullptr;
        }

        void setWidth(const int _w) { m_recProperties.m_width = _w; }
        void setHeight(const int _h) { m_recProperties.m_height = _h; }
        void setColor(const Color& _cl) { m_color(_cl); }
        void setFont(const Fonts& _f) { m_font(_f); }
    protected:
        std::string m_recName;
        Ordinate_Properties m_recProperties;
        Color m_color;
        Fonts* m_font;
};

class Circle : public Object {
        Circle()
        : m_cirName("") {}
        Circle(const std::string& _name, const Ordinate_Properties& _p, const Color& _cl)
        : m_cirName(_name), m_cirProperties(_p), m_color(_cl) {}
        ~Circle(){}

    public:
        Object* genetate_object(const std::vector<std::string>& properties) override {
            Circle* new_obj = nullptr;
            if (properties.size() == 10) {
                std::string name = properties[1];
                Ordinate_Properties propeties_ = {
                    .m_initX = std::stof(properties[2]),
                    .m_initY = std::stof(properties[3]),
                    .m_speedX = std::stof(properties[4]),
                    .m_speedY = std::stof(properties[5]),
                    .m_width = 0,
                    .m_height = 0,
                    .m_radius = std::stof(properties[9].c_str())
                };

                Color color_;
                color_.m_red = atoi(properties[6].c_str());
                color_.m_green = atoi(properties[7].c_str());
                color_.m_blue = atoi(properties[8].c_str());

                new_obj = new Circle(name, propeties_,color_);
            }
            else {
                new_obj = new Circle();
            }
            // Rectangle* 
            return nullptr;
        }
    protected:
        std::string m_cirName;
        Ordinate_Properties m_cirProperties;
        Color m_color;
        Fonts* m_font;
};

class Fonts : public Object {
        Fonts() {}
        Fonts(const std::string& _fname)
        : m_fname(_fname) {}
        Fonts(const Color& _color)
        : m_color(_color) {}
        Fonts(const int _size)
        : m_size(_size) {}
        Fonts(const std::string& _fname, const Color& _cl, const int _size)
        : m_fname(_fname), m_color(_cl), m_size(_size) {}

    public:
        virtual Object* genetate_object(const std::vector<std::string>& properties) = 0;
        ~Fonts() {}

        void setColor(const Color& _cl)  { m_color(_cl); }
        void setName(const std::string& _name) { m_fname = _name; }
        void setSize(const int _size) { m_size = _size; }
        Color getColor() const { return m_color; }
        std::string getFName() const { return m_fname; }
        int getSize() const { return m_size; }

        void operator()(const Fonts& _other) {
            this->m_fname = _other.m_fname;
            this->m_color = _other.m_color;
            this->m_size = _other.m_size;
        }

    protected:
        std::string m_fname{""};
        Color m_color;
        int m_size{0};
};

std::vector<std::string> read_config_line(const std::string& config_file) {
    std::vector<std::string> result_messages;
    std::fstream config_file_stream;
    config_file_stream.open(config_file, std::ios_base::in);
    while (!config_file_stream.eof()) {
        std::string message;
        std::getline(config_file_stream, message);
        std::cout << message << std::endl;
        result_messages.push_back(message);
    }
    config_file_stream.close();
    return result_messages;
}

// for string delimiter
std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

Object* parseObject(const std::string& _object_string, Parse_Type& _parse) {
    static std::unordered_map<std::string, Parse_Type> _handle = {
        {"Window",      Parse_Type::WINDOW},
        {"Font",        Parse_Type::FONT},
        {"Rectangle",   Parse_Type::RECT},
        {"Circle",      Parse_Type::CIRCLE}
    };
    auto foundIt = _handle.find(_handle[_temp[0]]);
    if (foundIt != _handle.end()) {
        std::cout << "Parse Type error! ";
        return nullptr;
    }

    Object* object = nullptr;
    _parse = foundIt->second;
    std::cout << "_object : " << _object_string << std::endl;    
    std::vector<std::string> _temp = split(_object_string, " ");

    // Release object
    switch (_parse)
    {
        case Parse_Type::WINDOW: {
            window = Window::genetate_object(_temp)
            break;
        }
        case Parse_Type::RECT: {
            object = Rectangle::genetate_object(_temp);
            break;
        }
        case Parse_Type::CIRCLE: {
            object = Circle::genetate_object(_temp);
            break;
        }
        default: {
            break;
        }
    }
    return object;
}

int main(void) {

    auto object_string = read_config_line("../configure.txt");
    sf::RenderWindow* window = nullptr;
    std::vector<sf::CircleShape> circleObjects;
    std::vector<sf::Shape> shapeObjects;
    // sf::Font font;
    // // if (!font.loadFromFile("fonts/Arial.ttf")) {
    // //     return EXIT_FAILURE;
    // // }
    for (auto obj_ : object_string) {
        Parse_Type _parse_type;
        Object* _obj =  parseObject(obj_, _parse_type);
        if (_obj != nullptr) {
            switch (_obj->m_type) {
                case Parse_Type::WINDOW: {
                    window = new sf::RenderWindow(sf::VideoMode(_obj->m_properties.width, _obj->m_properties.height), "Window");
                }
                case Parse_Type::FONT: {
                    if (!font.loadFromFile(""))
                    break;
                }
                case Parse_Type::CIRCLE: {
                    break;
                }
                case Parse_Type::RECT: {
                    
                    break;
                }
                default: {
                    break;
                }
            }
            std::cout << " Kind of object: " << static_cast<int>(_obj->m_type) << std::endl;
        }
    }

    // sf::CircleShape circle;
    // circle.setScale(1.0, 1.0);
    // circle.setFillColor(sf::Color::Blue);
    // circle.setRadius(50);
    // circle.setOutlineColor(sf::Color::Red);
    // circle.setPosition(10, 20);

    // // sf::Sprite sprite(texture);
    // // sprite.scale(sf::Vector2f{
    // //     2.5f, 2.5f
    // // });

    // // sf::Font font;
    // // if (!font.loadFromFile("fonts/Arial.ttf")) {
    // //     return EXIT_FAILURE;
    // // }

    // // sf::Text text("Hello World!", font, 50);
    // // text.setString(sf::String("Hello SFML"));
    // // text.setColor(sf::Color::White);

    do {
        
        if (window == nullptr) {
            std::cout << "Window is null" << std::endl;
            break;
        }

        while (window->isOpen()) {
            window->clear();
            sf::Event event;
            while (window->pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    std::cout << "Close Window" << std::endl;
                    window->close();
                }
            }
            window->setActive();

            // OpenGL drawing commands go here
            // window->draw(sprite);
            // window->draw(text);
            // window->draw(circle);

            // End the current frame and display its contents on scren
            window->display();
            usleep(1000);
        }
    } while(0);

    return 0;
}