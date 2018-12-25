class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> end;
        if(not A.size()) return A;
        for(auto it = --A.end(); it >= A.begin(); it--){
            if ((*it) % 2 == 0){
                end.insert(end.begin(), *it);
            } else {
                end.push_back(*it);
            }
        }
        return end;
    }
};