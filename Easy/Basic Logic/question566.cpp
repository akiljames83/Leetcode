class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size()*nums[0].size() != r * c) return nums;
        vector<vector<int>>::iterator it = nums.begin();
        vector<int>::iterator iit = it->begin();
        vector<vector<int>> res(r,vector<int>(c,0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res[i][j] = *iit++;
                if (iit == it->end()){
                    it++;
                    iit = it->begin();
                }
            }
        }
        return res;
    }
};