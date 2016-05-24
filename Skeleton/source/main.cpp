#include "cgate/log/logger_factory.hpp"
#include "SFML/Graphics.hpp"

#if defined(_WIN32)
#include <Windows.h>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main(int argc, char** argv)
#endif
{
    cgate::LoggerFactory::getSingleton().createFileLogger("file1", "file1.txt", true);
    cgate::LoggerFactory::getSingleton().createFileLogger("file2", "file2.txt", true);

    cgate::LoggerFactory::getSingleton().fatal(0, "FATAL ERROR : %s\n", "I am to good for this shit !!!");
/*
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
*/
    return 0;
}
