#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED
#include <string.h>
#include <map>
#include <SFML/Graphics.hpp>
class Animation
{
public:
    std::map<std::string,std::vector> animationMap;
    void createAnimation(std::string name, sf::Texture texture, bool loop); //Create an animation
    void addFrame(std::string name, sf::IntRect rectangle); //Add a frame to an animation
    void deleteFrame(std::string name); //Delete the last frame from the specified animation (unnessessary?)
    void play(std::string name); //play the animation
    void pause(); //pause the animation

private:

};

#endif // ANIMATION_H_INCLUDED
