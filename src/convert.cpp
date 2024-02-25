#include "convert.hpp"
#include "PriorityQueue.hpp"
#include <cstddef>
#include <istream>
#include <string>
#include <vector>
#include <unordered_map>
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
    std::vector<std::string> resultpath;
    if(start==end)
    {
        resultpath.push_back(start);
        return resultpath;
    }
    PriorityQueue<WordNode> explore;
    std::unordered_map<std::string, std::string> predecessors;
    explore.push(WordNode(start,differentChar(start, end)));
    size_t numfromStart = 0;
    while(!explore.empty())
    {
        std::string currentword = explore.min().Word;
        numfromStart = explore.min().totalDistance;
        explore.popMin();
        if(currentword==end)
        {
            for (std::string at = end; at != start; at = predecessors[at]) {
                resultpath.push_back(at);
            }
            resultpath.push_back(start);
            std::reverse(resultpath.begin(), resultpath.end());
            return resultpath;
        }
        for(size_t i=0;i<currentword.size();++i)
        {
            std::string nextword = currentword;
            for(char alpa = 'a'; alpa <= 'z'; ++alpa)
            {
                nextword[i] = alpa;
                if(words.contains(nextword)&&predecessors.find(nextword)==predecessors.end())
                {
                    predecessors[nextword] = currentword;
                    explore.push(WordNode(nextword, 1+numfromStart+differentChar(nextword, end)));
                }
            }
        }
    }
    return resultpath;
}

size_t differentChar(const std::string&current, const std::string&end)
{
    size_t char_num = 0;
    for(size_t i=0;i<current.length();i++)
    {
        if(current[i]!=end[i]){
            char_num++;
        }
    }
    return char_num;
}

}; // namespace shindler::ics46::project5
