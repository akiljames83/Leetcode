class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sa{}, sb{};
        for (auto a : A)
            sa += a;
        for (auto b : B)
            sb += b;
        int dif = (sb - sa)/2;
        int cur = 0;
        for(;;){
            for (int i = 0; i < B.size(); i++){
                if (B[i] - A[cur] == dif)
                    return {A[cur], B[i]};
            }
            cur++;
        }
    }
};

// Better solution using a set:
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sa{}, sb{};
        for (auto a : A)
            sa += a;
        for (auto b : B)
            sb += b;
        unordered_set<int> set{B.begin(), B.end()};
        int dif = (sb - sa)/2;
        for (int i = 0; i < A.size(); i++){
            if (set.find(A[i] + dif) != set.end())
                return {A[i], A[i]+dif};
        }
        
    }
};