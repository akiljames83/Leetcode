class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int width = A.size();
        int height = A[0].size();
        vector< vector<int> > ans(height, vector<int>(width, 0));
        for (int i = 0; i < width; i++){
            for (int j = 0; j < height; j++){
                ans[j][i] = A[i][j];
            }
        }
        return ans;
        
    }
};