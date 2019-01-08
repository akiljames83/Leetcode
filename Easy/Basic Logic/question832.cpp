class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if (A.size() == 0 || A[0].size() == 0) return A;
        // Flip the image
        for (int i = 0; i < A.size(); i++){
            int begin{};
            int end{A[0].size() -1 };
            while (end - begin > 0) {
                int temp = A[i][begin];
                A[i][begin++] = A[i][end];
                A[i][end--] = temp;
            }
        }
        // invert the image
        for (int i = 0; i < A.size(); i++){
            for (int j = 0; j < A[0].size(); j++){
                A[i][j] ^= 0x01;
            }
        }
        return A;
    }
};

// Faster solution, inplace, O(n*m), using easy bit manip;
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if (A.size() == 0 || A[0].size() == 0) return A;
        
        for (int i = 0; i < A.size(); i++){
            int begin{};
            int end{A[0].size() -1 };
            while (end - begin > 0) {
                int temp = A[i][begin];
                A[i][begin++] = A[i][end] ^ 0x01;
                A[i][end--] = temp ^ 0x01;
            }
            if (end == begin) A[i][begin] ^= 0x01;
        }
        return A;
    }
};