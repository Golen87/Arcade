#ifndef DESKTOPSTATE_H_INCLUDED
#define DESKTOPSTATE_H_INCLUDED
#include "../state.h"
class DesktopState: public State
{
public:
    DesktopState(){};
private:
    void input();
    void update();
    void draw();
};

#endif // DESKTOPSTATE_H_INCLUDED
