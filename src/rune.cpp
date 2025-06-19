#include "rune.h"

Rune::Rune(unsigned long bin) : m_rune(bin)
{}

std::string Rune::to_string(unsigned long bin) const {

    switch(bin) {
        case RUNE_VOWEL_A   :
            return "A";
        case RUNE_VOWEL_O   :
            return "O";
        case RUNE_VOWEL_I   :
            return "I";
        case RUNE_VOWEL_E   :
            return "E";
        case RUNE_VOWEL_OO_O:
            return "OO_O";
        case RUNE_VOWEL_ER  :
            return "ER";
        case RUNE_VOWEL_EE  :
            return "EE";
        case RUNE_VOWEL_OO_U:
            return "OO_U";
        case RUNE_VOWEL_IR  :
            return "IR";
        case RUNE_VOWEL_OOR :
            return "OOR";
        case RUNE_VOWEL_AR  :
            return "AR";
        case RUNE_VOWEL_ERE :
            return "ERE";
        case RUNE_VOWEL_AI  :
            return "AI";
        case RUNE_VOWEL_Y   :
            return "Y";
        case RUNE_VOWEL_U   :
            return "U";
        case RUNE_VOWEL_OW_H:
            return "OW_H";
        case RUNE_VOWEL_OW_S:
            return "OW_S";
        case RUNE_VOWEL_AIR :
            return "AIR";
        case RUNE_CONSONANT_B :
            return "B";
        case RUNE_CONSONANT_CH:
            return "CH";
        case RUNE_CONSONANT_D :
            return "D";
        case RUNE_CONSONANT_F :
            return "F";
        case RUNE_CONSONANT_G :
            return "G";
        case RUNE_CONSONANT_H :
            return "H";
        case RUNE_CONSONANT_J :
            return "J";
        case RUNE_CONSONANT_K :
            return "K";
        case RUNE_CONSONANT_L :
            return "L";
        case RUNE_CONSONANT_M :
            return "M";
        case RUNE_CONSONANT_N :
            return "N";
        case RUNE_CONSONANT_NG:
            return "NG";
        case RUNE_CONSONANT_P :
            return "P";
        case RUNE_CONSONANT_R :
            return "R";
        case RUNE_CONSONANT_S :
            return "S";
        case RUNE_CONSONANT_SH:
            return "SH";
        case RUNE_CONSONANT_T :
            return "T";
        case RUNE_CONSONANT_TH_S:
            return "TH_S";
        case RUNE_CONSONANT_TH_Z:
            return "TH_Z";
        case RUNE_CONSONANT_V :
            return "V";
        case RUNE_CONSONANT_W :
            return "W";
        case RUNE_CONSONANT_Y :
            return "Y";
        case RUNE_CONSONANT_Z :
            return "Z";
        case RUNE_CONSONANT_ZH:
            return "ZH";
    }
    return "";
} 

std::string Rune::to_string() const {
    if(m_rune == RUNE_NULL)
        return " ";

    unsigned long consonant = RUNE_CONSONANT & m_rune;
    unsigned long vowel = RUNE_VOWEL & m_rune;
    bool reverse = RUNE_REVERSE & m_rune;

    if(reverse)
        return std::string(Rune::to_string(vowel) + Rune::to_string(consonant));
    return std::string(Rune::to_string(consonant) + Rune::to_string(vowel));
}