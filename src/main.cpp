#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    cout << "Version " << myproject_VERSION_MAJOR << "." << myproject_VERSION_MINOR << endl;
    
    sf::RenderWindow screen(sf::VideoMode(800, 600), "myproject");
    
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
