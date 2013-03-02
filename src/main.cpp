#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Singleton/UniqueObject.cpp"

using namespace std;

int main()
{
    cout << "Version " << VERSION_MAJOR << "." << VERSION_MINOR << endl;
    
    UniqueObject *obj = UniqueObject::getInstance();

    cout<<obj->getValue()<<endl;
    obj->setValue(5);
    cout<<obj->getValue()<<endl;

    sf::RenderWindow screen(sf::VideoMode::getFullscreenModes()[0], EXECUTABLE_NAME);
    std::cout << "Mode : "
              << sf::VideoMode::getFullscreenModes()[0].width
              << "x" << sf::VideoMode::getFullscreenModes()[0].height << " - "
              << sf::VideoMode::getFullscreenModes()[0].bitsPerPixel << " bpp" << std::endl;

    sf::Texture Texture;
    Texture.loadFromFile("floor.jpg");

    sf::Sprite Sprite;
    Sprite.setTexture(Texture);

    while (screen.isOpen())
    {
        sf::Event event;
      
        while (screen.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                screen.close();
        }
        
        screen.clear();
        screen.draw(Sprite);
        
	    screen.display();
    }

return EXIT_SUCCESS;
}
