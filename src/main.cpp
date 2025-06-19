// Sample code
#include <iostream>
#include <vector>
#include <queue>
#include <filesystem>
#include "dictionary.h"
#include "notedetector.h"
#include "rune.h"
//#include "libtuneic.h"
namespace fs = std::filesystem;

const auto DICTIONARY_EN = fs::path("lang/dictionary.en.txt");

// prototypes
int test();
int detection(const fs::path& dictionary_file, const fs::path& audio_file, double note_length);

int main(int argc, char* argv[]) {

    std::cerr << "argc: " << argc << "   ";
    // TEST MODE
    if(argc == 1) {
        return test();
    }

    if (argc != 2 && argc != 3) {
        std::cerr << "Usage: " 
            << argv[0] << " <file.wav> [note_length_millisec=75]>" << std::endl
            << argv[0] << " (test mode)" << std::endl;
        return 1;
    }

    std::string audio_file = argv[1];

    double note_length = 75;
    if(argc >= 3) {
        note_length = std::stod(argv[2]);
    }

    return detection(DICTIONARY_EN, audio_file, note_length);
}

int detection(const fs::path& dictionary_file, const fs::path& audio_file, double note_length) {

    // DETECTION MODE
    Dictionary dictionary(dictionary_file);

    std::vector<float> audioData;

    NoteDetector noteDetector;
    std::vector<Note> detected_sequence;
    noteDetector.processFile(audio_file, detected_sequence, note_length);

    // detected sequence
    std::cout << "==== detected_sequence ====" << std::endl;
    for(size_t i = 0; i < detected_sequence.size(); ++i) {
        std::cout << note_to_string(detected_sequence[i]) << " ";
    }
    std::cout << std::endl << std::endl;

    auto note_sequence = noteDetector.get_clean_sequence(detected_sequence);

    // Afficher la séquence nettoyee
    std::cout << "==== NOTE SEQUENCE ====" << std::endl;
    for(size_t i = 0; i < note_sequence.size(); ++i) {
        std::cout << note_to_string(note_sequence[i]) << " ";
    }
    std::cout << std::endl << std::endl;


    std::string translated = dictionary.Translate(note_sequence);
    std::cout << std::endl ;
    std::cout << "==== TRANSLATION ==== " << std::endl << translated << std::endl << std::endl;

    return 0;
}

template <typename T>
int test_check(const T& expected, const T& result) {
    bool testOK = (result == expected);
    auto resultStr = testOK ? "[ OK ] " : "[ KO ] ";
    std::cout << resultStr << "expected: [" << expected << "]  result: [" << result << "]" << std::endl;
    return testOK ? 0 : 1;
}

int test() {
    std::cout << std::endl << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "==========       TEST MODE          ===========" << std::endl;
    std::cout << "===============================================" << std::endl;

    Dictionary dictionary(DICTIONARY_EN);

    const std::vector< std::pair<std::vector<Rune>, std::string> > test_set_001 = {
        { { Rune(RUNE_VOWEL_A) } , "A"  },
        { { Rune(RUNE_CONSONANT_R) } , "R"  },
        { { Rune(RUNE_VOWEL_OO_O) } , "OO_O"  },
        { { Rune(RUNE_CONSONANT_N) } , "N"  },
        { { Rune(RUNE_VOWEL_A) } , "A"  },
        { { Rune(RUNE_VOWEL_A) } , "A"  },
        { { Rune(RUNE_CONSONANT_R | RUNE_VOWEL_OO_O), Rune(RUNE_VOWEL_OO_U | RUNE_CONSONANT_N | RUNE_REVERSE) } , "ruin"  },
        { { Rune(RUNE_CONSONANT_S | RUNE_VOWEL_I), Rune(RUNE_CONSONANT_K | RUNE_VOWEL_AR) } , "seeker"  },
        { { Rune(RUNE_CONSONANT_R | RUNE_VOWEL_OO_O), Rune(RUNE_VOWEL_OO_U | RUNE_CONSONANT_N | RUNE_REVERSE) , Rune(RUNE_NULL), Rune(RUNE_CONSONANT_S | RUNE_VOWEL_I), Rune(RUNE_CONSONANT_K | RUNE_VOWEL_AR) } , "ruin seeker"  },
    };

    int nb_fails = 0;
    for(const auto& test : test_set_001) {
        auto rune_sequence = test.first;
        auto expected = test.second;

        auto translated = dictionary.Translate(rune_sequence);
        nb_fails += test_check(expected, translated);

    }

    return nb_fails;
}


