class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size())
            return 0;
        int i = 0;
        int prev = nums[i];
        for (int j = 1; j < nums.size(); j++) {
            if (prev != nums[j]) {
                nums[++i] = nums[j];
                prev = nums[j];
            } 
        }
        return i+1;
    }
};