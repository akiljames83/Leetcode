class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> set;
        for (auto c: s) {
            if (set.find(c) != set.end())
                set.erase(c);
            else
                set.insert(c);
        }
        if (set.size() < 2)
            return true;
        return false;
    }
};