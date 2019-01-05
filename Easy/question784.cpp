#define isAlph(c) (c >= 'a' and c <= 'z') || (c >= 'A' and c <= 'Z')
class Solution {
public:
    void perms(string S, int pos, unordered_set<string>&set){
        if (S.size() == pos) return;
        if (isAlph(S[pos])) {
            string tmp = S;
            tmp[pos] = std::tolower(S[pos]);
            set.insert(tmp);
            perms(tmp,pos+1,set);
            tmp[pos] = std::toupper(S[pos]);
            set.insert(tmp);
            perms(tmp,pos+1,set);
        }
        else
            perms(S,pos+1,set);
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        unordered_set<string>set;
        set.insert(S);
        perms(S, 0, set);
        for (auto i = set.begin(); i != set.end(); i++){
            res.push_back(*i);
        }
        return res;
    }
};

// Do it without a set
#define isAlph(c) (c >= 'a' and c <= 'z') || (c >= 'A' and c <= 'Z')
#define lower(c) (c >= 'a' and c <= 'z')
class Solution {
public:
    void perms(string S, int pos, vector<string>& vec){
        if (S.size() == pos) return;
        if (isAlph(S[pos])) {
            string tmp = S;
            if (lower(S[pos])){
                tmp[pos] = toupper(S[pos]);
            } else{
                tmp[pos] = tolower(S[pos]);
            }
            vec.push_back(tmp);
            perms(tmp,pos+1,vec);
        }
        perms(S,pos+1,vec);
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> res{1,S};
        perms(S, 0, res);
        return res;
    }
};