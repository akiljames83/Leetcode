class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() == 1) return true;
        int mov{0};
        for (int i = 1; i < A.size(); i++){
            int tmov = A[i] - A[i - 1];
            if (!tmov) continue;
            if (!mov){
                mov = tmov;
            }
            else {
                if (mov > 0 and tmov < 0) return false;
                if (mov < 0 and tmov > 0) return false;
            }
        }
        return true;
    }
};