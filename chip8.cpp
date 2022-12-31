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
    // Assumed that first byte is pc and second is pc+1
    opcode = memory[pc] << 8 | memory[pc + 1];

    // Decode Opcode
    switch(opcode & 0xF000)
    {
        // First hex number is 1
        case 0x0000:
            switch(opcode & 0x000F)
            {
                // 0x00E0
                case 0x0000:
                    // Clear the screen
                break;

                // 0x00EE
                case 0x000E:
                    // Return from subroutine
                break;

                default:
                    std::cout << "Bad opcode: " << opcode << std::endl;
            }
        break;

        // First hex number is 2
        // 0x2NNN
        case 0x2000:
            // Call subroutine at NNNN
        break;
    }


    // Execute Opcode
 
    // Update timers
}