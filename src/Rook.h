#pragma once

#include "GameObject.h"
#include "AnimatedSprite.h"


class Rook : public GameObject
{
public:
    Rook();
    
    void load() override;
    
    void preUpdate(float deltatime) override;
    void update(float deltatime) override;
    void postUpdate(float deltatime) override;
    
    void draw(sf::RenderWindow* window) override;
    
    void keyPressed(sf::Keyboard::Key key) override;
    void keyHeld(sf::Keyboard::Key key) override;
    void keyReleased(sf::Keyboard::Key key) override;
    
private:
    AnimatedSprite m_anim;
    bool m_is_moving;
};