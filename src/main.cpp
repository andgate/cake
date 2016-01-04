#include <SFML/Graphics.hpp>

#include "AnimatedSprite.h"

const float PLAYER_SPEED = 3.0f;

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Project Cake", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(sf::Vector2i(10,50));
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    
    sf::View cam = window.getDefaultView();
    
    AnimatedSprite rook_anim;
    rook_anim.loadFromFile("res/rook/rook.png", "res/rook/rook.yaml");
    rook_anim.set_curr("stand_forward");
    
    sf::Clock frameClock;
    
    bool is_player_moving(false);
    
    while(window.isOpen())
    {
        rook_anim.update(0.06f);
        
        sf::Event event;
        while( window.pollEvent(event) )
        {
            if( event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
            
            if( (event.type == sf::Event::KeyReleased) )
            {
                if(event.key.code == sf::Keyboard::Left)
                    rook_anim.set_curr("stand_left");
                else if(event.key.code == sf::Keyboard::Right)
                    rook_anim.set_curr("stand_right");
                else if(event.key.code == sf::Keyboard::Up)
                    rook_anim.set_curr("stand_backward"); 
                else if(event.key.code == sf::Keyboard::Down)
                    rook_anim.set_curr("stand_forward");
                
                is_player_moving = false;
            }
            
            if( (event.type == sf::Event::KeyPressed) && !is_player_moving )
            {
                if(event.key.code == sf::Keyboard::Left)
                    rook_anim.set_curr("move_left");
                else if(event.key.code == sf::Keyboard::Right)
                    rook_anim.set_curr("move_right");
                else if(event.key.code == sf::Keyboard::Up)
                    rook_anim.set_curr("move_backward"); 
                else if(event.key.code == sf::Keyboard::Down)
                    rook_anim.set_curr("move_forward");
                
                is_player_moving = true;
            }
        }
        
        sf::Time frameTime = frameClock.restart();
        
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
        
        window.setView(cam);
        window.clear(sf::Color(50, 50, 50, 255));
        
        window.draw(rook_anim.get_curr());
        
        window.display();
    }
    
    return EXIT_SUCCESS;
}