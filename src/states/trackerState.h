#ifndef TRACKERSTATE_H_INCLUDED
#define TRACKERSTATE_H_INCLUDED
#include "../tracker/tracker.h"
#include "../state.h"
#include "../objects/cursor.h"
#include "../game.h"
class TrackerState: public State
{
public:
    TrackerState(){};
    TrackerState(Game *pGame);
    void input();
    void update();
    void draw();
private:
    Cursor cursor;
};

#endif // TRACKERSTATE_H_INCLUDED
