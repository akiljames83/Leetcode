class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> chars;
        for (auto c : S) {
            if (c != '#')
                chars.push(c);
            else {
                if (!chars.empty())
                    chars.pop();
            }
                
        }
        vector<char> word1;
        vector<char> word2;
        while (!chars.empty()){
            char c = chars.top();
            word1.push_back(c);
            chars.pop();
        }
        for (auto c : T) {
            if (c != '#')
                chars.push(c);
            else {
                if (!chars.empty())
                    chars.pop();
            }   
        }
        while (!chars.empty()){
            char c = chars.top();
            word2.push_back(c);
            chars.pop();
        }
        if (word1.size() != word2.size()) return false;
        for (int i = 0; i < word1.size(); i++) {
            if (word1[i] != word2[i])
                return false;
        }
        return true;
        
    }
};