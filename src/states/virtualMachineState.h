#ifndef VIRTUALMACHINESTATE_H_INCLUDED
#define VIRTUALMACHINESTATE_H_INCLUDED
#include <cstdint>
#include <SFML/Graphics.hpp>
#include "../emulation/emulator.h"
#include "../state.h"
#include "../objects/cursor.h"
typedef uint8_t u8;
typedef uint16_t u16;

enum {A,B,C,D,H,L,PC,SP,IA};
enum {NOP, LD, ADD, SUB, DEC, INC, CP, JR, JP, OR, XOR, AND, NOT, RET};


#define LINES 20

/*
LD; Load register into memory or other register or vice-versa
ADD; Add to the accumulator
SUB; Subtract from the accumulator
DEC; Decrease value of register by one
INC; Increase value of register by one
CP; Reg A subtracted by another register and compared
JR; Jump relative
JP; Conditional jump
RET; Return

Registers:
S- Sign set?
Z- Value is zero?
P- Parity (is even?) or Overflow?
N- Last operation was Subtraction?
C- Carried? (Last result did not fit in register)
*/

class VirtualMachineState: public State
{
private:
    Emulator emulator;
    sf::Font vera;
    sf::Text header, address[20], instruction[20], raw[20], reg[9], flag[5];
    bool running = true;
    void drawText();
    void updateDebugger();
    std::string opToText(int op);
    Cursor cursor;
public:
    VirtualMachineState(Game *pGame);
    void input();
    void update();
    void draw();
};

#endif // VIRTUALMACHINESTATE_H_INCLUDED
