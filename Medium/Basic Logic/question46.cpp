class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>&res, int pos) {
        for (int i = pos; i < nums.size(); i++){
            swap(nums[i], nums[pos]);
            if (!res.size() or res.back() != nums)
                res.push_back(nums);
            helper(nums, res, pos+1);
            swap(nums[i], nums[pos]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        helper(nums, res, 0);
        return res;
    }
};