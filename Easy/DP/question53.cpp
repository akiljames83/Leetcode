class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> prev(nums.size(), 0);
        prev[0] = nums[0];
        int max_n = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prev[i] = max(prev[i-1] + nums[i], nums[i]);
            if (prev[i] > max_n)
                max_n = prev[i];
        }
        return max_n;
    }
};