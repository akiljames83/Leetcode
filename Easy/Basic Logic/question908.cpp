// Best Solution:
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int min{INT_MAX}, max{INT_MIN};
        for (auto c : A)
        {
            if (c > max) max = c;
            if (c < min) min = c;
        }
        int dif = max - min;
        if (dif <= K*2)
            return 0;
        return dif - 2*K;
    }
};

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        if (A.size() == 1)
            return 0;
        sort(A.begin(), A.end());
        int dif = A.back() - A.front();
        if (dif <= K*2)
            return 0;
        return dif - 2*K;
    }
};