class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        char prev{S[0]};
        int count{};
        vector<vector<int>> res;
        int i = 1;
        for (; i < S.length(); i++){
            if (S[i] == prev){
                if (!count){
                    count = 2;
                } else {
                    count++;
                }
            } else {
                if (count >= 3) {
                   res.push_back({i-count,i-1}); 
                }
                prev = S[i];
                count = 0;
            }
        }
        if (count >= 3) {
           res.push_back({i-count,i-1}); 
        }
        return res;
    }
};