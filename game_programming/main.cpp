#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <unordered_map>
#include <sstream>

enum Object_Type {
    WIND = 0,
    RECT,
    CIRL,
    FONT
};

enum Configure_Type : uint32_t {
    WINDOW  = 0,
    FONT,
    RECT,
    CIRL
};
class ObjectGeneric {
    public:
        ObjectGeneric* generate_object(const Object_Type& _typ) {

        }
};

class Fonts : public ObjectGeneric {
    
};

struct Color {
    int m_red{0};
    int m_green{0};
    int m_blue{0}; 
};

struct Properties {
    int width{0};
    int height{0};
    float scale{0.0};
    Properties() {}
    Properties(const int _width, const int _height, const float _scale = {0.0}) : width(_width), height(_height), scale(_scale) {}
    Properties(const Properties& _other) : width(_other.width), height(_other.height), scale(_other.scale) {}
};


struct Font {
    std::string m_family_name_file{""};
    Color m_color;
    int m_size{0};
    Font(){}
    Font(const std::string& _family_name, int _size, const Color& _color) : m_family_name_file(_family_name), m_color(_color), m_size(_size) {}
};

struct Position {
    public:
        void setInitX(const float& _val)    { m_initX = _val; }
        void setInitY(const float& _val)    { m_initY = _val; }
        void setSpeedX(const float& _val)   { m_speedX = _val; }
        void setSpeedY(const float& _val)   { m_speedY = _val; }
        void setWidth(const float& _val)    { m_width = _val; }
        void setHeight(const float& _val)   { m_height = _val; }
        void setColor(const Color& _val) { 
            m_color.m_red   = _val.m_red; 
            m_color.m_green = _val.m_green; 
            m_color.m_blue  = _val.m_blue; 
        }
    private:
        float m_initX;
        float m_initY;
        float m_speedX;
        float m_speedY;
        float m_width;
        float m_height;
        Color m_color;
};

struct Object {
    Properties m_properties;
    Configure_Type m_type;
    Font m_font;
    Color m_color;
    Object(){}
    // Create a font object
    Object(const Font& _other, const Configure_Type& _typ) : m_font(_other.m_family_name_file, _other.m_size, _other.m_color ) {}
    // Create a Shape of object
    Object(const Properties& _pro, const Configure_Type& _typ) : m_properties(_pro), m_type(_typ) {}
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

Object* parseObject(const std::string& _object_string) {
    Object* object = nullptr;
    static std::unordered_map<std::string, Configure_Type> _handle = {
        {"Window", Configure_Type::WINDOW},
        {"Font", Configure_Type::FONT},
        {"Rectangle", Configure_Type::RECT},
        {"Circle", Configure_Type::CIRL}
    };

    std::cout << "_object : " << _object_string << std::endl;    
    std::vector<std::string> _temp = split(_object_string, " ");

    // Release object
    switch (_handle[_temp[0]])
    {
        case Configure_Type::WINDOW: {
            Properties properties_(atoi(_temp[1].c_str()), atoi(_temp[2].c_str()));
            object = new Object(properties_, Configure_Type::WINDOW);
            break;
        }
        case Configure_Type::FONT: {
            object = new Object(
                Font(
                    _temp[1], 
                    atoi(_temp[2].c_str()),
                    Color {
                    .m_red = atoi(_temp[3].c_str()),
                    .m_green = atoi(_temp[4].c_str()),
                    .m_blue =  atoi(_temp[5].c_str())
                }),
                Configure_Type::FONT);
            break;
        }

        case Configure_Type::RECT: {

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
    sf::Font font;
    // // if (!font.loadFromFile("fonts/Arial.ttf")) {
    // //     return EXIT_FAILURE;
    // // }

    for (auto obj_ : object_string) {
        Object* _obj =  parseObject(obj_);
        if (_obj != nullptr) {
            switch (_obj->m_type) {
                case Configure_Type::WINDOW: {
                    window = new sf::RenderWindow(sf::VideoMode(_obj->m_properties.width, _obj->m_properties.height), "Window");
                }

                case Configure_Type::FONT: {
                    if (!font.loadFromFile(""))
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