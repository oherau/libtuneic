#include "dictionary.h"
#include "notedetector.h"
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm> // For std::count_if
#include <cctype>    // For std::isalnum

const std::string DICT_ENTRY_SEPARATOR = "=";
const std::string DICT_COMMENT = "#";

Dictionary::Dictionary(const fs::path& filePath) {
    Load(filePath);
}

long count_notes(const std::string& str) {
    long unsigned int count = 0;
    for(const char c : str) {
        if(c >= 'A' && c <= 'G')
            count++;
    }
    return count;
}

bool Dictionary::Load(const fs::path& filePath) {

    printf("Loading dict file: %s\n", filePath.string().c_str());
    std::ifstream file(filePath);
    if(!file.is_open()) {
        printf("Error loading dict file: %s\n", filePath.string().c_str());
        return false;
    }

        
    std::string line;
    while (std::getline(file, line)) {
        //printf("%s\n", line.c_str());

        auto pos = line.find(DICT_ENTRY_SEPARATOR);
        if(pos != std::string::npos) {
            auto wordNotes = std::string(line.substr(0, pos));
            auto wordTranslation = std::string(line.substr(pos+DICT_ENTRY_SEPARATOR.size()));
            printf("[%s] = [%s]\n", wordNotes.c_str(), wordTranslation.c_str());
            long unsigned int nbNotes = count_notes(wordNotes);

            if(nbNotes > 0) {
                if(m_hashtable.contains(wordNotes)) {
                    printf("WARNING : duplicate entry [%s]\n", wordNotes.c_str());
                } 
                else {
                    m_hashtable[wordNotes] = wordTranslation;
                    
                    //printf(" nbNotes = %lu\n", nbNotes);
                    notes_max_length = std::max(notes_max_length, nbNotes);
                    notes_min_length = std::min(notes_min_length, nbNotes);
                }
            }
        }

    }
    file.close();

    // printf("%s\n\nm_hashtable:\n", line.c_str());

    // for(const auto& [key, value] : m_hashtable) {
    //     printf("[%s] = [%s]\n", key.c_str(), value.c_str());
    // }

    printf("\n");
    return true;
}

bool Dictionary::Save(const fs::path& filePath) {
    std::ofstream file(filePath);
    if(!file.is_open())
        return false;

    std::string line;
    for(auto const& [wordPhonetic, wordTranslation] : m_hashtable) {
        file << wordPhonetic << DICT_ENTRY_SEPARATOR << wordTranslation << std::endl;
    }
    file.close();

    return true;
}

std::string Dictionary::Translate(const std::string& str) {

    if(m_hashtable.contains(str))
        return m_hashtable[str];
    
    // word not found but added to be saved in file
    if(m_learning)
        m_hashtable[str] = str;

    return "";
}

std::string Dictionary::Translate(const std::vector<Note>& notes) {
    std::stringstream ssout;
    std::deque<Note> noteBuffer;

    // std::cout << "--- START TRANSLATION ---" << std::endl;
    // std::cout << "  notes_min_length: " << notes_min_length << std::endl;
    // std::cout << "  notes_max_length: " << notes_max_length << std::endl;
    for(const auto& note : notes) {
        noteBuffer.push_back(note);
        if(noteBuffer.size() > notes_max_length) {
            noteBuffer.pop_front();
        }

        std::deque<Note> wordBuffer(noteBuffer);
        while(wordBuffer.size() >= notes_min_length ) {

            std::string str = notes_to_string(wordBuffer, true);
            // std::cout << "  try to translate: " <<  str << std::endl;
            std::string translated = Translate(str);
            // std::cout << "  translated: " <<  translated << std::endl;

            if(translated.size() > 0) {
                std::cout << str << " => " <<  translated << std::endl;
                ssout << translated << " ";
                noteBuffer.clear();
                wordBuffer.clear();
                break; // while
            }
            wordBuffer.pop_front();
        }
    }

    return std::string(ssout.str());
}

std::string Dictionary::Translate(const std::vector<Rune>& runes) {

    std::stringstream ss;
    for(const auto& rune : runes) {
        ss << rune.to_string();
    }

    return std::string(ss.str());
}