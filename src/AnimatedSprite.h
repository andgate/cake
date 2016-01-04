#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <vector>

class AnimatedSprite
{
public:
    AnimatedSprite();
    
    bool loadFromFile(std::string sprite_sheet_path, std::string config_path);
    void update(float dt);
    sf::Sprite get_curr();
    void set_curr(std::string animation_name);
    
private:
    
    struct Frame
    {
        sf::IntRect cell;
        float time;
    };
    typedef std::vector<Frame> Frames;
    
    sf::Texture m_sprite_sheet_tex;
    sf::Sprite m_curr_sprite;
    std::string m_curr_anim_name;
    int m_cell_size;
    Frame m_curr_frame;
    int m_curr_frame_index;
    float m_time_elapsed;
    std::unordered_map<std::string, Frames> m_anim_map;
    
    Frame make_frame(int cell_x, int cell_y, float time);
    void nextFrame();
};