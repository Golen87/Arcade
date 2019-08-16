#include "virtualMachineState.h"
#include "../game.h"
#include <string>
#include <SFML/Audio.hpp>
#include <cmath>

VirtualMachineState::VirtualMachineState(Game *pGame)
{
    game = pGame;
    game->renderWindow.setMouseCursorVisible(true); //Doesn't seem to work
    game->renderWindow.setView(sf::View(sf::FloatRect(0,0,256*2,240*2)));//384,360)));
    emulator.setup();


    cursor = Cursor(game->resourceManager.getTexture("cursor"));

    if (!vera.loadFromFile("font/amiga4ever.ttf"))
    {
        std::cout << "WELP" << std::endl;
    }
    header.setFont(vera);
    header.setCharacterSize(8);
    header.setString("|ADDRESS| INSTRUCTION |  RAW  | REGISTER | FLAG  |");
    address[3].setColor(sf::Color::Black);
    instruction[3].setColor(sf::Color::Black);
    raw[3].setColor(sf::Color::Black);
    for (int i = 0; i < LINES; i++)
    {
        address[i].setFont(vera);
        address[i].setCharacterSize(8);
        address[i].setPosition(0,(i+2)*8);
        address[i].setString("0x0000");

        instruction[i].setFont(vera);
        instruction[i].setCharacterSize(8);
        instruction[i].setPosition(8*9,(i+2)*8);
        instruction[i].setString("LD A, 2000");

        raw[i].setFont(vera);
        raw[i].setCharacterSize(8);
        raw[i].setPosition(8*22,(i+2)*8);
        raw[i].setString("0x0000");
    }
    for (int i = 0; i < 9; i++)
    {
        reg[i].setFont(vera);
        reg[i].setCharacterSize(8);
        reg[i].setPosition(8*30,(i+2)*8);
        reg[i].setString("A: ");
    }
    for (int i = 0; i < 5; i++)
    {
        flag[i].setFont(vera);
        flag[i].setCharacterSize(8);
        flag[i].setPosition(8*40,(i+2)*8);
        flag[i].setString("C: ");
    }
    /*
    //test code from SFML itself
    const unsigned SAMPLES = 44100;
	const unsigned SAMPLE_RATE = 44100;
	const unsigned AMPLITUDE = 30000;

	sf::Int16 raw[SAMPLES];

	const double TWO_PI = 6.28318;
	double increment = 440./44100;
	double x = 0;
	for (unsigned i = 0; i < SAMPLES; i++) {
		raw[i] = AMPLITUDE * sin(x*TWO_PI);
		x += increment;
	}

	sf::SoundBuffer Buffer;
	if (!Buffer.loadFromSamples(raw, SAMPLES, 1, SAMPLE_RATE)) {
		std::cerr << "Loading failed!" << std::endl;
		return;
	}

	sf::Sound Sound;
	Sound.setBuffer(Buffer);
	Sound.setVolume(50);


	//Sound.setLoop(true);
	Sound.play();


    sf::sleep(sf::milliseconds(900));


	Sound.play();
    Sound.setPlayingOffset(sf::milliseconds(0));
    Sound.setPitch(1.2f);

	//Sound.setLoop(true);
	//Sound.play();

    sf::sleep(sf::milliseconds(900));


	Sound.play();
    Sound.setPlayingOffset(sf::milliseconds(0));
    Sound.setPitch(1.1f);
    sf::sleep(sf::milliseconds(900));


	Sound.play();
    Sound.setPlayingOffset(sf::milliseconds(0));
    Sound.setPitch(1.30f);
    sf::sleep(sf::milliseconds(1000));
    */

}

void VirtualMachineState::drawText()
{
    game->renderWindow.draw(header);
    for (int i = 0; i < LINES; i++)
    {
        game->renderWindow.draw(address[i]);
        game->renderWindow.draw(instruction[i]);
        game->renderWindow.draw(raw[i]);
    }
    for (int i = 0; i < 9; i++)
    {
        game->renderWindow.draw(reg[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        game->renderWindow.draw(flag[i]);
    }
}

void VirtualMachineState::updateDebugger()
{
    for (int i = 0; i < LINES; i++)
    {
        address[i].setString(std::to_string((emulator.getRegister(PC)+i-3)%65536));
        instruction[i].setString(opToText(emulator.getMemory((emulator.getRegister(PC)+i-3)%65536)));
        raw[i].setString(std::to_string(emulator.getMemory((emulator.getRegister(PC)+i-3)%65536)));
    }
    for (int i = 0; i < 9; i++)
    {
        reg[i].setString( emulator.getRegisterName(i) + ": " + std::to_string(emulator.getRegister(i)));
    }
    for (int i = 0; i < 5; i++)
    {
        flag[i].setString( emulator.getFlagName(i) + ": " + std::to_string(emulator.getFlag(i)));
    }
}

std::string VirtualMachineState::opToText(int op)
{
    std::string text;
    u16 o = (op & 0b1111110000000000) >> 10;
    u16 r1 = (op& 0b0000001111100000) >> 5;
    u16 r2 = op& 0b0000000000011111;
    switch(o)
    {
    case NOP:
        return text = "NOP ";
    case LD:
        return text = "LD  " + emulator.getRegisterName( r1 ) + "," + emulator.getRegisterName( r2 ) ;
    case ADD:
        return text = "ADD " + emulator.getRegisterName( r1 );
    case SUB:
        return text = "SUB " + emulator.getRegisterName( r1 );
    case RET:
        return text = "RET ";
    default:
        return text = "?";
    }
}

void VirtualMachineState::input(){};
void VirtualMachineState::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (!emulator.process())
        {
            std::cout << "End of program" << std::endl;
        }
        std::cout << "---------memory(64) = " << emulator.getMemory(64) << "------------"<< std::endl;
        std::cout << "---------register(a) = " << emulator.getRegister(0) << "------------"<< std::endl;
        sf::sleep(sf::milliseconds(500));
    }
    cursor.update(game->renderWindow);
    updateDebugger();
}
void VirtualMachineState::draw()
{
    drawText();
    //game->renderWindow.draw(cursor.sprite);
}
