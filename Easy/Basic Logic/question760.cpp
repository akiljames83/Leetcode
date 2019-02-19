class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> map;
        for (int i = 0; i < B.size(); i++) {
            map[B[i]] = i;
        }
        for (int i = 0; i < A.size(); i++) {
            A[i] = map[A[i]];
        }
        return A;
    }
};