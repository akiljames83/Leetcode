class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size() ? nums[0] : 0;
        vector<int> dp;
        int s = nums.size();
        dp.assign(s, 0);
        dp[0] = nums[0], dp[1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            int back = i != 2 ? max(dp[i-2], dp[i-3]) : dp[i-2];
            dp[i] = max(nums[i] + back, dp[i-1]);
        }
        return max(dp[s-1], dp[s-2]);
    }
};