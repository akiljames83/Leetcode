// Question 500.cpp
#include <algorithm>
class Solution {
public:
    map <char, int> row1{
        {'q', 0},
        {'w', 0},
        {'e', 0},
        {'r', 0},
        {'t', 0},
        {'y', 0},
        {'u', 0},
        {'i', 0},
        {'o', 0},
        {'p', 0}
        
    };
    map <char, int> row2{
        {'a', 0},
        {'s', 0},
        {'d', 0},
        {'f', 0},
        {'g', 0},
        {'h', 0},
        {'j', 0},
        {'k', 0},
        {'l', 0}        
    };
    map <char, int> row3{
        {'z', 0},
        {'x', 0},
        {'c', 0},
        {'v', 0},
        {'b', 0},
        {'n', 0},
        {'m', 0}    
    };
    bool check(string word, map <char, int> &row){
        for (auto c: word){
            if(row.find(c) == row.end()) return false;
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for (auto word: words){
            string copy = word;
            std::transform(copy.begin(), copy.end(), copy.begin(), ::tolower);
            if (row1.find(copy[0]) != row1.end()){
                if (check(copy, row1))
                    res.push_back(word);
            } else if (row2.find(copy[0]) != row2.end()) {
                if (check(copy, row2))
                    res.push_back(word);
            } else {
                if (check(copy, row3))
                    res.push_back(word);
            } 
        }
        return res;
    }
};