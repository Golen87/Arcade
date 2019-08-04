#include "animation.h"

Animation::Animation(int frameLength,int width, int height,std::initializer_list<sf::Vector2i> frameList)
{
    //set texture and size
    this->frameLength = frameLength;
    this->width = width;
    this->height = height;

    std::initializer_list<sf::Vector2i>::iterator it;
    for (it = frameList.begin(); it != frameList.end(); ++it)
    {
        addFrame(*it);
    }

}

Animation::Animation(int frameLength,int width, int height,std::initializer_list<sf::Vector2i> frameList, bool loop)
{
    //set texture and size
    this->frameLength = frameLength;
    this->width = width;
    this->height = height;
    this->loop = loop;

    std::initializer_list<sf::Vector2i>::iterator it;
    for (it = frameList.begin(); it != frameList.end(); ++it)
    {
        addFrame(*it);
    }

}


/*
Animation::Animation(int width, int height ,int nFrames, ...)
{
    //set texture and size
    this->texture = texture;
    this->width = width;
    this->height = height;

    sf::Vector2i v;
    va_list argList;
    va_start(argList, nFrames);
    for (int i = 0; i < nFrames; i++)
    {
        v = va_arg(argList,sf::Vector2i);
        addFrame(v);
    }
    va_end(argList);

}
*/

void Animation::addFrame(sf::Vector2i iFrame) //Add a frame to an animation
{
    frame.push_back(sf::IntRect(width*iFrame.x,height*iFrame.y,width,height));
}

void Animation::deleteFrame() //Delete the last frame from the specified animation (unnecessary?)
{
    //if the frame vector is not full then we can delete the last frame
    if (frame.size() != 0)
    {
        frame.pop_back();
    }
}

void Animation::setFrame(int x)
{
    //make sure the frame can actually be set and also that the frame vector is not empty...
    if (x >= 0 && x < frame.size() && frame.size() > 0)
    {
        //..now we can set the frame
        currentFrame = x;
    }
}


void Animation::animate(sf::Sprite &sprite) //Animate the sprite
{
    elapsedTime++;
    //If we haven't animated yet...
    if (!animateIt)
    {
        //...and we have waited for long enough...
        if (elapsedTime > frameLength)
        {
            //then let's animate the sprite
            animateIt = true;
        }
    }
    //..if we need to animate the sprite
    else if (animateIt)
    {

        currentFrame++;
        if(currentFrame > frame.size()-1)
        {
            //Loop the animation
            if (loop == true)
            {
                currentFrame = 0;
            }
            //If we're supposed to stop at the last frame
            else if (loop == false)
            {
                currentFrame = frame.size()-1;
            }
        }
        //std::cout << currentFrame << std::endl;
        sprite.setTextureRect(frame.at(currentFrame));
        animateIt = false;
        elapsedTime = 0; //restart the timer
    }

}
