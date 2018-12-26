#include <map>
class Solution {
public:
    bool judgeCircle(string moves) {
        map<char, int> pmap {
            {'U', 0},
            {'D', 0},
            {'R', 0},
            {'L', 0}
        };
        for (auto ch : moves){
            pmap[ch] += 1;
        }
        return (pmap['U'] - pmap['D'] || pmap['R'] - pmap['L']) ? false : true;
    }
};