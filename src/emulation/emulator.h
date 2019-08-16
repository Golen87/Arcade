#ifndef EMULATOR_H_INCLUDED
#define EMULATOR_H_INCLUDED
#include <iostream>
#define nReg 9 //number of registers
#define nFlag 5 //number of flags
typedef uint8_t u8;
typedef uint16_t u16;

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

Flags:
S- Sign set?
Z- Value is zero?
P- Parity (is even?) or Overflow?
N- Last operation was Subtraction?
C- Carried/Borrowed? (Last result did not fit in register)

INSTRUCTION FORMAT:

An instruction is a single word in memory.
It can determine what the next word of memory represents.

-What does it looks like?---------
LET A REPRESENT THE FIRST REGISTER
LET B REPRESENT THE SECOND REGISTER
LET O REPRESENT THE OPCODE
OOOOOOAAAAABBBBB
----------------------------------
The size of A and B is 5 bits (together they are 10 bits)
The size of O is 6 bits
For a total of 16 bits (one word)



=====================================================
Notes:
** = the value in the PC
(**) = the value that the PC references

*/



class Emulator
{
    //debug functions
public:
    u16 getMemory(u16 i)
    {
        return memory[i];
    }
    void setMemory(u16 m, u16 v) //set a value in memory to something
    {
        memory[m] = v;
    }
    u16 getRegister(u16 r)
    {
        return reg[r];
    }
    void setRegister(u16 r, u16 v)
    {
        reg[r] = v;
    }
    std::string getRegisterName(u16 r)
    {
        if (r < nReg)
        {
            return regName[r];
        }
        else if (r == nReg || r == (nReg+1))
        {
            return "(**)";
        }
        else if (r == (nReg+2))
        {
            return "**";
        }
        return "err";
    }
    u16 getFlag(u16 f)
    {
        return flag[f];
    }
    std::string getFlagName(u16 f)
    {
        return flagName[f];
    }

    void checkZero() //check if the accumulator is zero
    {
        if (rA == 0) //register is equal to zero
            fZ = true;
        else //register is not equal to zero
            fZ = false;
    }
    void checkSign() //check if accumulator is signed
    {
        u16 r = (rA & 0b1000000000000000) >> 15;
        if (r == 1)
            fS = true;
        else
            fS = false;
    }

private:
    std::string regName[nReg] = {"A","B","C","D","H","L","PC","SP","IA"};
    std::string flagName[5] = {"S","Z","P","N","C"};
    enum {A,B,C,D,H,L,PC,SP,IA};
    enum {NOP, LD, ADD, SUB, DEC, INC, CP, JR, JP, OR, XOR, AND, NOT, RET};

    u16 memory[0x10000] = {}, reg[nReg] = {}; //MEMORY: a,b,c,d,SP,PC,IA
    bool flag[5] = {}; //S Z P N C

    bool &fS = flag[0];
    bool &fZ = flag[1];
    bool &fP = flag[2];
    bool &fN = flag[3];
    bool &fC = flag[4];

    u16 &rA  = reg[A];
    u16 &rB = reg[B];
    u16 &rC  = reg[C];
    u16 &rD  = reg[D];
    u16 &rH  = reg[H];
    u16 &rL  = reg[L];
    u16 &rPC = reg[PC];
    u16 &rSP = reg[SP];
    u16 &rIA = reg[IA];

    //u16 reg16[3]; //PC, SP, IA
    //next instruction
    void tick(u16 n = 1)
    {
        reg[PC] += n;
    }
public:
    void setup();
    //check for overflow
    bool isCarry(int i);
    //load operation
    void load(u16 r1, u16 r2);
    //add operation
    void add(u16 r);
    //subtraction operation
    void sub(u16 r);
    //process the instructions in RAM
    bool process();
    //run the program
    void run();
public:
};


#endif // EMULATOR_H_INCLUDED
