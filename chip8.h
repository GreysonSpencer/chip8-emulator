#ifndef CHIP8_H
#define CHIP8_H

class chip8 {
    private:
        // Currently loaded opcode
        unsigned short opcode;

        // 4K of memory
        //0x000-0x1FF - Chip 8 interpreter (contains font set in emu)
        //0x050-0x0A0 - Used for the built in 4x5 pixel font set (0-F)
        //0x200-0xFFF - Program ROM and work RAM
        unsigned char memory[4096];

        // 16 8-bit registers
        unsigned char V[16];

        // Index register
        unsigned short I;

        // Program counter
        unsigned short pc;

        // Delay and sound timer
        // When above 0, will count down to 0 at 60hz
        unsigned char delay_timer;
        unsigned char sound_timer;

        // Stack levels and stack pointer
        unsigned short stack[16];
        unsigned short sp;

        // Hex based keypad
        // 0x0-0xF
        unsigned char key[16];
};

#endif