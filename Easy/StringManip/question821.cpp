class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int first{S.find(C)};
        int prev{first};
        int last{S.rfind(C)};
        int size = S.size();
        vector<int> res(size, 0);
        for (int i = 0; i < size; i++){
            if (i <= first) {
                res[i] = first - i;
            } else if (i >= last) {
                res[i] = i - last;
            } else {
                int j{i};
                while(j != size){
                    if ((j - i >= i - prev) and (i - prev > 0)) {
                        res[i] = i - prev;
                        break;
                    } 
                    if (S[j] == C) {
                        prev = j;
                        res[i] = prev - i;
                        break;
                    }
                    j++;
                }
            }
        }
        return res;
    }
};

// Better solution - not mine:
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> sol(S.size(), INT32_MAX);
        int cur = -1, i = 0;
        for(auto n: S) {
            if(n == C) cur = 0;
            if(cur != -1) sol[i] = cur++;
            i++;
        }
        
        for(i--; i >= 0; i--) {
            if(S[i] == C) cur = 0;
            sol[i] = min(sol[i], cur++);
        }
        
        return sol;
    }
};

// Another sexc solution using builtins:
vector<int> shortestToChar(string S, char C) {
    vector<int> nums;
    for (size_t i = 0; i < S.size(); ++i) {
        auto l = S.find_last_of(C, i);
        auto r = S.find_first_of(C, i);
        if (l == string::npos) {
            nums.emplace_back(r - i);
        } else if (r == string::npos) {
            nums.emplace_back(i - l);
        } else {
            nums.emplace_back(min(i - l, r - i));
        }
    }
    return nums;
}