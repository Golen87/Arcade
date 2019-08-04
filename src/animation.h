#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED
#include <string.h>
#include <map>
#include <SFML/Graphics.hpp>
#include <stdarg.h>
#include <initializer_list>
class Animation
{
public:
    Animation(){};
    Animation(int frameLength, int width, int height,std::initializer_list<sf::Vector2i> v);
    Animation(int frameLength, int width, int height,std::initializer_list<sf::Vector2i> v, bool loop);
    void addFrame(sf::Vector2i v); //Add a frame to an animation
    void deleteFrame(); //Is this necessary?
    void setFrame(int x); //set it to the appropriate frame
    void animate(sf::Sprite &sprite);

private:
    //int frameDuration; //duration of a single frame
    int currentFrame = 0;
    int elapsedTime = 0;
    int frameLength = 10; //time is taken in terms of frames
    bool animateIt = false;
    bool loop = true;
    int width;
    int height;
    //sf::Texture texture;
    std::vector<sf::IntRect> frame;
};

#endif // ANIMATION_H_INCLUDED

/*

class Animation
{
public:
    //void createAnimation(std::string name, sf::Texture &texture, bool loop); //Create an animation
    void addFrame(std::string name, sf::IntRect rectangle, bool loop); //Add a frame to an animation
    void deleteFrame(std::string name); //Delete the last frame from the specified animation (unnessessary?)
    void play(std::string name); //play the animation
    void pause(); //pause the animation
    void animate(sf::Sprite &sprite);

private:
    std::map<std::string,std::vector<sf::IntRect> > animationMap;
};


#endif // ANIMATION_H_INCLUDED
*/
