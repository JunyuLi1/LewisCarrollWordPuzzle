#ifndef __PROJECT5_HPP
#define __PROJECT5_HPP

#include <string>
#include <unordered_set>
#include <vector>

namespace shindler::ics46::project5 {

void loadWordsIntoTable(std::unordered_set<std::string>& words,
                        std::istream& istream);

std::vector<std::string> convert(const std::string& start,
                                 const std::string& end,
                                 const std::unordered_set<std::string>& words);

}  // namespace shindler::ics46::project5
#endif
