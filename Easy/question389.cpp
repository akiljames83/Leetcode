

// Using a vector instead of map
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<char> map(26,0);
        for (auto c: s){
            map[c - 'a']++;
        }
        for (auto c: t){
            if (!map[c - 'a']) return c;
            map[c - 'a']--;
        }
    }
};