// Question 884
class Solution {
public:
    void check(unordered_set<string>& mset, string str, unordered_set<string>& repeats){
        for (int i{}, begin{}; i < str.size(); i++){
            if (str[i] == ' '){
                string tmp = str.substr(begin,i-begin);
                if (mset.find(tmp) != mset.end()) 
                    repeats.insert(tmp);
                mset.insert(tmp);
                begin = i + 1;
            }
            if (i+1 == str.size()){
                string tmp = str.substr(begin,i-begin + 1);
                if (mset.find(tmp) != mset.end()) 
                    repeats.insert(tmp);
                mset.insert(tmp);
            }
        }

        
    }
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_set <string> sa, sb, repeats;
        vector <string> result;
        check(sa, A, repeats);
        check(sb, B, repeats);
        
        for (auto str: sa){
            if((sb.find(str) == sb.end()) and (repeats.find(str) == repeats.end()))
                result.push_back(str);
            else
                sb.erase(str);
        }
        
        for (auto str: sb) {
            if (!(repeats.find(str) == repeats.end()))
                continue;
            result.push_back(str);
        }
        
        return result;
    }
};

// Version 2: Cleaner code when adding 2 strings
class Solution {
public:
    vector<string> check(string str, unordered_set<string>& set, unordered_set<string>& repeats){
        vector <string> res;
        for (int i{}, begin{}; i < str.size(); i++){
            if (str[i] == ' '){
                string tmp = str.substr(begin,i-begin);
                if (set.find(tmp) != set.end())
                    repeats.insert(tmp);
                set.insert(tmp);
                begin = i + 1;
            }
            if (i+1 == str.size()){
                string tmp = str.substr(begin,i-begin + 1);
                if (set.find(tmp) != set.end())
                    repeats.insert(tmp);
                set.insert(tmp);   
            }
        }
        for (auto s: set)
            if (repeats.find(s) == repeats.end()) 
                res.push_back(s);
        return res;
        
    }
    vector<string> uncommonFromSentences(string A, string B) {
        string sentence = A + " " + B;
        unordered_set<string> set, repeats;
        return check(sentence, set, repeats);

    }
};

// Version 3: map!
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        string str = A + " " + B;
        unordered_map<string, int> map;
        vector <string> res;
        for (int i{}, begin{}; i < str.size(); i++){
            
            if (str[i] == ' '){
                map[str.substr(begin,i-begin)]++;
                begin = i + 1;
            }
            
            if (i+1 == str.size())
                map[str.substr(begin,i-begin + 1)]++;   
        }
        for (auto s: map)
            if (s.second == 1) res.push_back(s.first);
        
        return res;

    }
};
