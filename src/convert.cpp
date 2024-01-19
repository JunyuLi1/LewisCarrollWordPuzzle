#include "convert.hpp"

#include <istream>
#include <string>
#include <unordered_set>

namespace shindler::ics46::project5 {

// You should not need to change this function.
void loadWordsIntoTable(std::unordered_set<std::string>& words,
                        std::istream& istream) {
    std::string word;

    while (istream >> word) {
        words.insert(word);
    }
}

// You probably want to change this function.
std::vector<std::string> convert(const std::string& start,
                                 const std::string& end,
                                 const std::unordered_set<std::string>& words) {
    return {};
}

};  // namespace shindler::ics46::project5
