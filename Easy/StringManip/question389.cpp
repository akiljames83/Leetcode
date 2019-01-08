// Fastest solution is with an array instead of vector:
class Solution {
public:
    char findTheDifference(string s, string t) {
        char map [26]{0};
        for (auto c: s){
            map[c - 'a']++;
        }
        for (auto c: t){
            if (!map[c - 'a']) return c;
            map[c - 'a']--;
        }
    }
};

// Similarily fast way using xor;
class Solution {
public:
    char findTheDifference(string s, string t) {
        int res{0};
        for (auto c : s) {
            res ^= static_cast<int>(c);
        }
        for (auto c : t) {
            res ^= static_cast<int>(c);
        }
        return static_cast<int>(res);
    }
};

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

// Using a map:
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> smap;
        for (auto c: s){
            if (smap.find(c) != smap.end()){
                smap[c]++;
            } else {
                smap[c] = 1;
            }
        }
        for (auto c: t){
            if (smap.find(c) != smap.end()){
                smap[c]--;
                if (!smap[c]) smap.erase(c);
            }
            else{
                return c;
            }
        }
    }
};