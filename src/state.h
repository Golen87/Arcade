#ifndef STATE_H
#define STATE_H
class Game;
class State
{
public:
    State();
    State(Game * pGame);
    void logic();
protected:
    Game * game;
    virtual void input();
    virtual void update();
    virtual void draw();
};
#endif
