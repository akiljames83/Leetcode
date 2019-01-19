class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (!nums.size())
            return 0;
        int prev = nums[0];
        int count{1};
        int t_count{1};
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > prev) {
                t_count++;
                prev = nums[i];
            } else {
                if (t_count > count)
                    count = t_count;
                t_count = 1;
                prev = nums[i];
            }
        }
        if (t_count > count)
            count = t_count;
        return count;
    }
};