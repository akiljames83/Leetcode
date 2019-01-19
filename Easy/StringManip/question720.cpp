class Solution {
public:
    string longestWord(vector<string>& words) {
        std::sort(words.begin(), words.end());
        unordered_set<string> set;
        set.insert("");
        string long_w{""};
        for (auto w: words){
            if (set.find(w.substr(0,w.length()-1)) != set.end()) {
                set.insert(w);
                if (w.length() > long_w.length()){
                    long_w = w;
                } else if (w.length() == long_w.length()){
                    if (strcmp(w.c_str(), long_w.c_str()) < 0) {
                        long_w = w;
                    }
                }
            }
        }
        return long_w;
    }
};