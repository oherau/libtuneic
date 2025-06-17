#ifndef __RUNE_H__
#define __RUNE_H__

#include <string>

/*
           
VOWELS
          /  \
       2 /    \ 1
        /      \
       |
     3 |
       |
     ------------------
       |
     3 |
       |
        \       /
       4 \     / 5
          \   /
            O
            12

CONSONANTS
            7
         \  |  /
        8 \ | / 6
           \|/
            |
     ------------------
            |
           /|\
        9 / | \ 11
         /  |  \
            10

*/

//                                  ___________|
const auto RUNE_REVERSE         = 0b000000000001;

//                                  |||||_______
const auto RUNE_VOWEL_A         = 0b111000000000; // cat
const auto RUNE_VOWEL_O         = 0b011000000000; // on
const auto RUNE_VOWEL_I         = 0b000110000000; // ship
const auto RUNE_VOWEL_E         = 0b001110000000; // bed
const auto RUNE_VOWEL_OO_O      = 0b001100000000; // good
const auto RUNE_VOWEL_ER        = 0b110000000000; // teacher

const auto RUNE_VOWEL_EE        = 0b011110000000; // sheep
const auto RUNE_VOWEL_OO_U      = 0b111100000000; // shoot
const auto RUNE_VOWEL_IR        = 0b101110000000; // bird
const auto RUNE_VOWEL_OOR       = 0b111010000000; // door
const auto RUNE_VOWEL_AR        = 0b110110000000; // far
const auto RUNE_VOWEL_ERE       = 0b011010000000; // here

const auto RUNE_VOWEL_AI        = 0b010000000000; // wait
const auto RUNE_VOWEL_Y         = 0b100000000000; // my
const auto RUNE_VOWEL_U         = 0b000100000000; // up
const auto RUNE_VOWEL_OW_H      = 0b000010000000; // cow
const auto RUNE_VOWEL_OW_S      = 0b111110000000; // show
const auto RUNE_VOWEL_AIR       = 0b001010000000; // hair



//                                  _____||||||_
const auto RUNE_CONSONANT_M     = 0b000000001010;
const auto RUNE_CONSONANT_N     = 0b000000011010;
const auto RUNE_CONSONANT_NG    = 0b000000111110;
const auto RUNE_CONSONANT_P     = 0b000001000100;
const auto RUNE_CONSONANT_B     = 0b000000100010;
const auto RUNE_CONSONANT_T     = 0b000001010100;


const auto RUNE_CONSONANT_D     = 0b000000101010;
const auto RUNE_CONSONANT_K     = 0b000001100010;
const auto RUNE_CONSONANT_G     = 0b000001000010;
const auto RUNE_CONSONANT_J     = 0b000000101000;
const auto RUNE_CONSONANT_CH    = 0b000000010100;
const auto RUNE_CONSONANT_F     = 0b000001001100;

const auto RUNE_CONSONANT_V     = 0b000000110010;
const auto RUNE_CONSONANT_TH_Z  = 0b000000101110;
const auto RUNE_CONSONANT_TH_S  = 0b000001110100;
const auto RUNE_CONSONANT_S     = 0b000001101100;
const auto RUNE_CONSONANT_Z     = 0b000000110110;
const auto RUNE_CONSONANT_SH    = 0b000001011110;

const auto RUNE_CONSONANT_ZH    = 0b000001111010;
const auto RUNE_CONSONANT_H     = 0b000000100110;
const auto RUNE_CONSONANT_R     = 0b000001100100;
const auto RUNE_CONSONANT_Y     = 0b000000110100;
const auto RUNE_CONSONANT_W     = 0b000001010000;
const auto RUNE_CONSONANT_L     = 0b000000100100;



class Rune {
public:
    Rune() = default;
    Rune(unsigned long vowel,  unsigned long consonant, bool reverse);
    unsigned long vowel = 0;
    unsigned long consonant = 0;
    bool reverse = false;
    std::string to_string();
    std::string to_string(unsigned long elem);
};

#endif // __RUNE_H__