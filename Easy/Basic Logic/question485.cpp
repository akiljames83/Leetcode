class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        bool wasOne = nums[0];
        int count{};
        int tmp{};
        for (auto n : nums){
            if(n){
                if (!wasOne){
                    wasOne = true;
                }
                tmp++;
            }
            else {
                count = max(tmp,count);
                tmp = 0;
                wasOne = false;
            }
        }
        if (nums.back())
            count = max(tmp,count);
        return count;
    }
};