#include <SFML/Graphics.hpp>

#include "Rook.h"
#include "AnimatedSprite.h"

const float PLAYER_SPEED = 3.0f;
const float DELTA_TIME = 0.01666666666;

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Project Cake", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(sf::Vector2i(10,50));
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    
    sf::View cam = window.getDefaultView();
    
    Rook rook;
    rook.load();
    
    //sf::Clock frameClock;
    
    
    while(window.isOpen())
    {
        rook.preUpdate(DELTA_TIME);
        
        sf::Event event;
        while( window.pollEvent(event) )
        {
            if( event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
            
            if( (event.type == sf::Event::KeyReleased) )
            {
                rook.keyReleased(event.key.code);
            }
            
            if( (event.type == sf::Event::KeyPressed))
            {
                rook.keyPressed(event.key.code);
            }
        }
        
        rook.update(DELTA_TIME);
        
        // Essentially the physics update
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            cam.move(PLAYER_SPEED,0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            cam.move(-PLAYER_SPEED,0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            cam.move(0,PLAYER_SPEED);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            cam.move(0,-PLAYER_SPEED);
        }
        
        rook.postUpdate(DELTA_TIME);
        
        window.setView(cam);
        window.clear(sf::Color(50, 50, 50, 255));
        
        rook.draw(&window);
        
        window.display();
    }
    
    return EXIT_SUCCESS;
}