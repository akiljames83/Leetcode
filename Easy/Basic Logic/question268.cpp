class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int tot{};
        for (int i = 0; i < nums.size(); i++){
            tot -= nums[i];
            tot += i;
        }
        return tot + nums.size();
    }
};