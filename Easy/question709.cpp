#include <sstream>
class Solution {
public:
    string toLowerCase(string str) {
        stringstream ss;
        std::locale loc;
        for (char& ch : str) // c++11 way of iterating through strings
            ss << std::tolower(ch, loc);
        return ss.str();
    }
};