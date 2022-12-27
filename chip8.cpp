#include "chip8.h"

void chip8::initialize()
{
    pc = 0x200; // Every program starts at 0x200 or 512
    opcode = 0; // Reset opcode
    I = 0; // Reset index register
    sp = 0; // Reset stack pointer

    // Clear display
    // Clear stack
    // Clear registers V0-VF
    // Clear memory

    // Load fontset
    // for (int i = 0; i < 80; i++)
    // {
    //     memory[i] = chip8_fontset[i];
    // }
    
    // Reset timers
}
 
void chip8::emulateCycle()
{
  // Fetch Opcode
  // Decode Opcode
  // Execute Opcode
 
  // Update timers
}