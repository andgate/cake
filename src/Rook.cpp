#include "Rook.h"

Rook::Rook()
: m_anim()
, m_is_moving(false)
{
    
}

void Rook::load()
{
    m_anim.loadFromFile("res/rook/rook.png", "res/rook/rook.yaml");
    m_anim.set_curr("stand_forward");
}

void Rook::preUpdate(float deltatime)
{
    m_anim.update(deltatime);
}

void Rook::update(float deltatime)
{
}

void Rook::postUpdate(float deltatime)
{
}

void Rook::draw(sf::RenderWindow* window)
{
    window->draw(m_anim.get_curr());
}

void Rook::keyPressed(sf::Keyboard::Key key)
{
    if(!m_is_moving)
    {
        if(key == sf::Keyboard::Left)
            m_anim.set_curr("move_left");
        else if(key == sf::Keyboard::Right)
            m_anim.set_curr("move_right");
        else if(key == sf::Keyboard::Up)
            m_anim.set_curr("move_backward"); 
        else if(key == sf::Keyboard::Down)
            m_anim.set_curr("move_forward");
        
        m_is_moving = true;
    }
}

void Rook::keyHeld(sf::Keyboard::Key key)
{
    
}

void Rook::keyReleased(sf::Keyboard::Key key)
{
    if(m_is_moving)
    {
        if(key == sf::Keyboard::Left)
            m_anim.set_curr("stand_left");
        else if(key == sf::Keyboard::Right)
            m_anim.set_curr("stand_right");
        else if(key == sf::Keyboard::Up)
            m_anim.set_curr("stand_backward"); 
        else if(key == sf::Keyboard::Down)
            m_anim.set_curr("stand_forward");
        
        m_is_moving = false;
    }
}