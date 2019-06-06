class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (auto word : words)
            if (match(word, pattern))
                res.push_back(word);
        return res;
    }
    
    bool match(string word, string pattern) {
        if (word.length() != pattern.length()) return false;
        unordered_map<char, char> ref;
        unordered_set<char> set;
        
        for (int i = 0; i < word.length(); i++) {
            if (ref.find(word[i]) != ref.end()){
                if (ref[word[i]] != pattern[i])
                    return false;
            } else {
                if (set.find(pattern[i]) != set.end())
                    return false;
                ref[word[i]] = pattern[i];
                set.insert(pattern[i]);
            }
        }
        
        return true;
    }
};

auto fast_io =[](){std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();