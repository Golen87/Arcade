#include "emulator.h"

void Emulator::setup()
{
    std::cout << "--Setup--\n";
    rPC = 0;
    memory[reg[0x10000-0x1]] = RET; //let's just make the last segment of memory return

    //Program
    memory[0]  = 0b0000010000001011; //ld a, **
    memory[1]  = 0b1000000000011111; //** = 32799
    memory[2]  = 0b0000010100100000; //Ld (**), a
    memory[3]  = 0b0000000001000000; //** = 64
    memory[4]  = 0b0000010000001010; //ld a, (**)
    memory[5]  = 0b0000000000000011; // ** = 3
    memory[6]  = 0b0000110000000000; // sub a
    memory[7]  = 0b0011010000000000; // Return
    //
    std::cout << "--DONE--\n";
}

bool Emulator::isCarry(int i)
{
    return (i > 65535);
}

//load operation
void Emulator::load( u16 r1, u16 r2 )
{
    std::cout << "LOAD ";
    if (r1 >= nReg) //if the register is not valid on a
    {
        if (r1 == nReg) //one over the last register
        {
            //Load (**), r2
            tick();
            setMemory(getMemory(rPC),reg[r2]);
            std::cout << "("<< getMemory(rPC) << ")" << ", "<< regName[r2] << std::endl;
        }
        else if (r1 == nReg+1)//two over the last register
        {
            //Load r2, (**)
            tick();
            setRegister(r2,getMemory(getMemory(rPC)));
        }
        else //if we need to load a number into a register
        {
            //Load r2, **
            tick();
            setRegister(r2,getMemory(rPC));
        }
    }
    else if (r2 >= nReg) // if the register is not valid on b
    {
         if (r2 == nReg) //one over the last register
        {
            //Load (**), r1
            tick();
            setMemory(getMemory(rPC),reg[r1]);
        }
        else if (r2 == nReg+1) //two over the last register
        {
            //Load r1, (**)
            tick();
            setRegister(r1,getMemory(getMemory(rPC)));
            std::cout << regName[r1] << ", ("<< getMemory(rPC) << ")" << std::endl;
        }
        else
        {
            //Load r1, **
            tick();
            setRegister(r1,getMemory(rPC));

            std::cout << regName[r1] << ", "<< getMemory(rPC) << std::endl;
        }
    }
    else//if the registers are valid
    {
        reg[r1] = reg[r2]; //load register a, register b
    }
}

void Emulator::add(u16 r) //you only ever add to the A register
{
    //reset subtraction flag
    fN = false;
    //set carry flag
    if (r >= nReg)
        std::cerr << "This register does not exist" << std::endl;
    else if (isCarry(rA += reg[r]))
    {
        fC = true;
        std::cout << "overflow" << std::endl;
    }
    else //did not carry
    {
        fC = false;
    }
    std::cout << "ADD " << regName[r] << std::endl;
}

void Emulator::sub(u16 r)//you only ever sub to the A register
{
    //set subtraction flag
    fN = true;
    //set carry flag
    if (r >= nReg)
        std::cerr << "This register does not exist" << std::endl;
    else if (isCarry(rA -= reg[r]))
    {
        fC = true;
        std::cout << "underflow" << std::endl;
    }
    else //did not carry
    {
        fC = false;
    }
}

bool Emulator::process()
{
   {
        u16 opcode = (memory[reg[PC]]  & 0b1111110000000000) >> 10;  //AND to get opcode part of the instruction
        u16 r1     = (memory[reg[PC]]  & 0b0000001111100000) >> 5; //get the second register
        u16 r2     = (memory[reg[PC]]  & 0b0000000000011111); //get the first register

        switch(opcode)
        {
        case NOP: //do nothing
            std::cout << "NOP" << std::endl;
            tick();
            break;
        case LD:
            load(r1,r2);
            //std::cout << "instruction at memory[5] = " << getMemory(5) << std::endl;
            tick(); //next instruction
            break;
        case ADD:
            add(r1);
            tick();
            break;
        case SUB:
            sub(r1);
            tick();
            break;
        case DEC:
            break;
        case INC:
            break;
        case CP:
            break;
        case JR:
            break;
        case JP:
            break;
        case OR:
            break;
        case XOR:
            break;
        case AND:
            break;
        case NOT:
            break;
        case RET:
            std::cout << "RET: Program stopped at location: " << reg[PC] << std::endl;
            return false;
            //break;
        default:
            std::cerr << "Instruction not recognized\n";
            std::cout << "Program stopped at location: " << reg[PC] << std::endl;
            return false;
            //break;
        }
        //set Zero flag
        checkZero();
        checkSign();

        return true;
    }
}
