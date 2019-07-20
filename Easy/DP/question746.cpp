class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp;
        dp.assign(cost.size()+1, 0);
        dp[1] = cost[0];
        for (int i = 2; i <= cost.size(); i++){
            dp[i] = cost[i-1] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[cost.size() - 1], dp[cost.size()]);
    }
};