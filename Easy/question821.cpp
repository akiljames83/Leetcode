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