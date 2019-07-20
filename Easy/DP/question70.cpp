class Solution {
public:
    int climbStairs(int n) {
        // base case
        int dp1 = 1, dp2 = 2, cur;
        if (n < 3)
            return (n == 1) ? dp1 : dp2;
        for (int i = 3; i <= n; i++, dp1=dp2, dp2=cur) {
            cur = dp1 + dp2;
        }
        return cur;
    }
};