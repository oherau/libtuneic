// Sample code
#include <iostream>
#include <queue>
#include <filesystem>
#include "dictionary.h"
#include "notedetector.h"
//#include "libtuneic.h"
namespace fs = std::filesystem;

const auto DICTIONARY_EN = fs::path("lang/dictionary.en.txt");

int main(int argc, char* argv[]) {
    if (argc != 2 && argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <file.wav> [note_length_millisec=75]>" << std::endl;
        return 1;
    }

    Dictionary dictionary(DICTIONARY_EN);
    std::string filename = argv[1];
    double note_length = 75;
    if(argc >= 3) {
        note_length = std::stod(argv[2]);
    }
    std::vector<float> audioData;

    NoteDetector noteDetector;
    std::vector<Note> detected_sequence;
    noteDetector.processFile(filename, detected_sequence, note_length);

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


