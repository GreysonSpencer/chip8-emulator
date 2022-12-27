#ifndef CHIP8_H
#define CHIP8_H

#include <string.h>

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

        unsigned char chip8_fontset[80] =
        { 
            0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
            0x20, 0x60, 0x20, 0x20, 0x70, // 1
            0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
            0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
            0x90, 0x90, 0xF0, 0x10, 0x10, // 4
            0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
            0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
            0xF0, 0x10, 0x20, 0x40, 0x40, // 7
            0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
            0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
            0xF0, 0x90, 0xF0, 0x90, 0x90, // A
            0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
            0xF0, 0x80, 0x80, 0x80, 0xF0, // C
            0xE0, 0x90, 0x90, 0x90, 0xE0, // D
            0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
            0xF0, 0x80, 0xF0, 0x80, 0x80  // F
        };

    public:
        // Initialize registers and memory
        void initialize();

        // Fetch Opcode
        // Decode Opcode
        // Execute Opcode
        // Update timers
        void emulateCycle();
};

#endif