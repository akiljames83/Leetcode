class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int>map;
        for (auto c: s) {
           if (map.find(c) != map.end())
               map[c]++;
            else
                map[c] = 1;
        }
        for (auto c: t) {
            if (map.find(c) != map.end()){
                //cout << c << " " << map[c] << endl;
                if (!--map[c])
                    map.erase(c);
            }
            else
                return false;
        }
        return true;
    }
};

// Un-portable array version
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int>map(26,0);
        for (auto c: s)
           map[c-'a']++;
        for (auto c: t) {
            if (!map[c-'a']--)
                return false;
        }
        return true;
    }
};

// Slighty better version: Using an array instead of a vector
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int map [26]{};
        for (auto c: s)
           map[c-'a']++;
        for (auto c: t) {
            if (!map[c-'a']--)
                return false;
        }
        return true;
    }
};
