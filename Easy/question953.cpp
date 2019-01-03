class Solution {
public:
    bool cmp(string w1, string w2, unordered_map<char,int>& dict){
        int n = min(w1.size(), w2.size());
        for (int i = 0; i < n; i++){
            if (dict[w1[i]] > dict[w2[i]]) 
                return false;
            else if (dict[w1[i]] == dict[w2[i]])
                continue;
            else
                return true;
        }
        if (w1.size() > n) 
            return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map <char,int> dict;
        for(int i = 0; i < order.size(); i++)
            dict[order[i]] = i;
        for (int i = 1; i < words.size(); i++)
            if (!cmp(words[i-1],words[i],dict))
                return false;
        return true;
    }
};