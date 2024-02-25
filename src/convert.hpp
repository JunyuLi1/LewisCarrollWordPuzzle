#ifndef __PROJECT5_HPP
#define __PROJECT5_HPP

#include <cstddef>
#include <string>
#include <unordered_set>
#include <vector>

namespace shindler::ics46::project5 {

void loadWordsIntoTable(std::unordered_set<std::string>& words,
                        std::istream& istream);

std::vector<std::string> convert(const std::string& start,
                                 const std::string& end,
                                 const std::unordered_set<std::string>& words);

struct WordNode{
    std::string Word;
    size_t totalDistance;
    WordNode(std::string word, int distance) : Word(word), totalDistance(distance) {}
    bool operator<(const WordNode& rhs) const {
        return this->totalDistance < rhs.totalDistance;
    }
    bool operator==(const WordNode& rhs) const {
        return this->totalDistance == rhs.totalDistance;
    }
};

size_t differentChar(const std::string&current, const std::string&end);

}  // namespace shindler::ics46::project5
#endif
