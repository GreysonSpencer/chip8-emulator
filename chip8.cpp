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
        // Call subroutine at NNN
        case 0x2000:
            stack[sp] = pc;
            sp++;
            pc = opcode & 0x0FFF;
        break;

        // First hex number is 3
        // 0x3XNN
        // Skips next instruction if VX equals NN
        case 0x3000:
            unsigned char x = opcode & 0x0F00;
            unsigned char nn = opcode & 0x00FF;

            if(V[x] == nn)
                pc += 4;
            else
                pc += 2;
        break;

        // First hex number is 4
        // 0x4XNN
        // Skips next instruction if VX does not equal NN
        case 0x4000:
            unsigned char x = opcode & 0x0F00;
            unsigned char nn = opcode & 0x00FF;

            if(V[x] != nn)
                pc += 4;
            else
                pc += 2;
        break;

        // First hex number is 5
        // 0x5XY0
        // Skips next instruction if VX equals VY
        case 0x5000:
            unsigned char x = opcode & 0x0F00;
            unsigned char y = opcode & 0x00F0;

            if(V[x] == V[y])
                pc += 4;
            else
                pc += 2;
        break;

        // First hex number is 6
        // 0x6XNN
        // Sets VX equal to NN
        case 0x6000:
            unsigned char x = opcode & 0x0F00;
            unsigned char nn = opcode & 0x00FF;

            V[x] = nn;
            pc += 2;
        break;

        // First hex number is 7
        // 0x7XNN
        case 0x7000:
            // Adds NN to VX
        break;

        // First hex number is 8
        case 0x8000:
            switch(opcode & 0x000F)
            {
                // Sets Vx equal to Vy
                case 0x0000:
                    unsigned char x = opcode & 0x0F00;
                    unsigned char y = opcode & 0x00F0;

                    V[x] = V[y];
                    pc += 2;
                break;
                // Sets Vx equal to Vx or Vy
                case 0x0001:
                    unsigned char x = opcode & 0x0F00;
                    unsigned char y = opcode & 0x00F0;

                    V[x] = V[x] | V[y];
                    pc += 2;
                break;
                // Sets Vx equal to Vx and Vy
                case 0x0002:
                    unsigned char x = opcode & 0x0F00;
                    unsigned char y = opcode & 0x00F0;

                    V[x] = V[x] & V[y];
                    pc += 2;
                break;
                // Sets VX to VX xor VY
                case 0x0003:
                    unsigned char x = opcode & 0x0F00;
                    unsigned char y = opcode & 0x00F0;

                    V[x] = V[x] ^ V[y];
                    pc += 2;
                break;
                // Adds VY to VX. VF is set to 1 when there's a carry, and to 0 when there is not
                case 0x0004:
                break;
                // VY is subtracted from VX. VF is set to 0 when there's a borrow, and 1 when there is not
                case 0x0005:
                break;
                // Stores the least significant bit of VX in VF and then shifts VX to the right by 1
                case 0x0006:
                break;
                // Sets VX to VY minus VX. VF is set to 0 when there's a borrow, and 1 when there is not
                case 0x0007:
                break;
                // Stores the most significant bit of VX in VF and then shifts VX to the left by 1
                case 0x000E:
                break;
            }
        break;

        // First hex number is 9
        case 0x9000:
            // 
        break;
        // First hex number is A
        case 0xA000:
            // 
        break;
        // First hex number is B
        case 0xB000:
            // 
        break;
        // First hex number is C
        case 0xC000:
            // 
        break;
        // First hex number is D
        case 0xD000:
            // 
        break;
        // First hex number is E
        case 0xE000:
            // 
        break;
        // First hex number is F
        case 0xF000:
            // 
        break;
    }


    // Execute Opcode
 
    // Update timers
}