#include "AnimatedSprite.h"

#include <yaml-cpp/yaml.h>

AnimatedSprite::AnimatedSprite()
: m_sprite_sheet_tex()
, m_curr_sprite()
, m_curr_anim_name()
, m_cell_size(0)
, m_curr_frame()
, m_curr_frame_index()
, m_time_elapsed()
, m_anim_map()
{
}

bool AnimatedSprite::loadFromFile(const std::string sprite_sheet_path, const std::string config_path)
{
    if(!m_sprite_sheet_tex.loadFromFile(sprite_sheet_path))
        // file not found error
        return EXIT_FAILURE;
    m_curr_sprite.setTexture(m_sprite_sheet_tex);
    
    YAML::Node config = YAML::LoadFile(config_path);
    
    if(!config["cell_size"])
        // missing filed "cell-size"
        return EXIT_FAILURE;
    if(!config["animations"])
        // missing field animations
        return EXIT_FAILURE;
    
    m_cell_size = config["cell_size"].as<int>();
    
    auto animations = config["animations"];
    
    for (int anim_index = 0; anim_index < animations.size(); anim_index++)
    {
        std::string animation_name = animations[anim_index]["name"].as<std::string>();
        auto frames_yaml = animations[anim_index]["frames"];
        Frames frames;
        
        for (int frame_index = 0; frame_index < frames_yaml.size(); frame_index++)
        {
            int cell_x = frames_yaml[frame_index]["cell_x"].as<int>();
            int cell_y = frames_yaml[frame_index]["cell_y"].as<int>();
            
            float time(0.0f);
            if(frames_yaml[frame_index]["time"])
                time = frames_yaml[frame_index]["time"].as<float>();
            
            frames.push_back(make_frame(cell_x, cell_y, time));
        }
        
        m_anim_map.insert(std::pair<std::string, Frames>(animation_name, frames));
    }
}

void AnimatedSprite::update(float dt)
{
    m_time_elapsed += dt;
    if(m_time_elapsed >= m_curr_frame.time)
    {
        m_time_elapsed = m_time_elapsed - m_curr_frame.time;
        nextFrame();
    }
}

sf::Sprite AnimatedSprite::get_curr()
{
    return m_curr_sprite;
}

void AnimatedSprite::set_curr(std::string animation_name)
{
    // reset time_elapsed
    m_curr_anim_name = animation_name;
    m_curr_frame_index = 0;
    
    m_curr_frame = m_anim_map[m_curr_anim_name][m_curr_frame_index];
    m_curr_sprite.setTextureRect(m_curr_frame.cell);
}

AnimatedSprite::Frame AnimatedSprite::make_frame(int cell_x, int cell_y, float time)
{
    int left = cell_x * m_cell_size;
    int top = cell_y * m_cell_size;
    int width = m_cell_size;
    int height = m_cell_size;
    
    Frame frame;
    frame.cell = sf::IntRect(left, top, width, height);
    frame.time = time;
    
    return frame;
}

void AnimatedSprite::nextFrame()
{   
    auto frames = m_anim_map[m_curr_anim_name];
    if(m_curr_frame_index+1 < frames.size())
    {
        m_curr_frame_index += 1;
    }
    else
    {
        m_curr_frame_index = 0;
    }
    
    m_curr_frame = m_anim_map[m_curr_anim_name][m_curr_frame_index];
    m_curr_sprite.setTextureRect(m_curr_frame.cell);
}
