#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <map>
#include <vector>
#include <string>
#include <limits>
#include <filesystem>
#include "note.h"
namespace fs = std::filesystem;

class Dictionary {
public:
    Dictionary() = default;
    Dictionary(const fs::path& filePath);
    bool Load(const fs::path& filePath);
    bool Save(const fs::path& filePath);
    std::string Translate(const std::string& str);
    std::string Translate(const std::vector<Note>& notes);
private:
    bool m_learning = false;
    std::map<std::string, std::string> m_hashtable;
    long unsigned int notes_min_length = std::numeric_limits<long unsigned int>::max();
    long unsigned int notes_max_length = 0;
};

#endif // __DICTIONARY_H__