class Solution {
public:
    bool checkRecord(string s) {
        bool hasA = false;
        bool oneL = false;
        bool twoL = false;
        for (auto c : s){
            if (c == 'A'){
                oneL = false;
                twoL = false;
                if (hasA){
                    return false;
                }
                hasA = true;
            } else if (c == 'L') {
                if (oneL and twoL){
                    return false;
                } else if (oneL) {
                    twoL = true;
                } else {
                    oneL = true;
                }
            } else {
                oneL = false;
                twoL = false;
            }
        }
        return true;
    }
};