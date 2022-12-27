#include "chip8.h"

void chip8::initialize()
{
    pc = 0x200; // Every program starts at 0x200 or 512
    opcode = 0; // Reset opcode
    I = 0; // Reset index register
    sp = 0; // Reset stack pointer

    // Clear display

    // Clear stack
    for (int i = 0; i < 16; i++)
        stack[i] = 0;

    // Clear registers V0-VF
    for (int i = 0; i < 16; i++)
        V[i] = 0;
    
    // Clear memory
    memset(memory, 0, 4096);
    

    // Load fontset
    for (int i = 0; i < 80; i++)
    {
        memory[i] = chip8_fontset[i];
    }
    
    // Reset timers
    delay_timer = 0;
    sound_timer = 0;
}
 
void chip8::emulateCycle()
{
    // Fetch Opcode
    // Decode Opcode
    // Execute Opcode
 
    // Update timers
}