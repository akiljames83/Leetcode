// Question 893
// Runtime complexity: O(n*(n - 1)*str*log(str))
// At each loop, there are at most n - 1 items in the groups vector and there are n items in A
// then the string is iterated through twice: once in decompress and once in cmp;
// then the string is sorted in decompress ~ nlogn
class Solution {
public:
    pair<string, string> decompress(string str){
        string even;
        string odd;
        bool check = true;
        for (auto ch: str) {
            if (check)
                even.push_back(ch);   
            else 
                odd.push_back(ch); 
            check = !check;
        }
        std::sort(even.begin(), even.end());
        std::sort(odd.begin(), odd.end());
        return make_pair(even, odd);
    }
    int cmp(string A, string B){
        if (A.size() != B.size()) return 1;
        for (int i = 0; i < A.size(); i++){
            if (A[i] != B[i]) return 1;
        }
        return 0;
    }
    int numSpecialEquivGroups(vector<string>& A) {
        vector<int> groups;
        vector< pair<string, string> > stringcheck;
        for (auto str: A){
            // decompose the string to even and odds
            pair<string, string> tmp = decompress(str);
            int i = 0;
            bool change = false;
            for(auto pairs: stringcheck){
                if (!cmp(pairs.first, tmp.first) and !cmp(pairs.second, tmp.second)){
                    groups[i]++;
                    change = !change;
                    break;
                }
                i++;  
            }
            if (!change){
                stringcheck.push_back(tmp);
                groups.push_back(0);
            }
        }

        return groups.size();
    }
};

// Version 2:
// Runtime analysis -> O(n*str*log(str));
// Items are looped through one at a time, then each character in string is iterated through in decompress;
// constant amortized time insertion to a set
// then string is sorted in decompress so ~nlogn
class Solution {
public:
    string decompress(string str){
        string even;
        string odd;
        bool check = true;
        for (auto ch: str) {
            if (check)
                even.push_back(ch);   
            else 
                odd.push_back(ch); 
            check = !check;
        }
        std::sort(even.begin(), even.end());
        std::sort(odd.begin(), odd.end());
        return even + odd;
    }
    
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set <string> groups;
        for (auto str: A)
            groups.insert(decompress(str));
        
        return groups.size();
    }
};