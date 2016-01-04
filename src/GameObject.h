#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
    virtual ~GameObject() {}
    
    virtual void load() {};
    
    // Before input update
    virtual void preUpdate(float deltatime) {};
    // After input update, before physics update
    virtual void update(float deltatime) {};
    // After physics update
    virtual void postUpdate(float deltatime) {};
    
    virtual void draw(sf::RenderWindow* window) {};
    
    
    virtual void keyPressed(sf::Keyboard::Key key) {};
    virtual void keyHeld(sf::Keyboard::Key key) {};
    virtual void keyReleased(sf::Keyboard::Key key) {};
};