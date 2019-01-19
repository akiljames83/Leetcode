class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count{nums.size()};
        for (int i = 0; i < count; i++) {
            if (nums[i] == val) {
                int j = i;
                while(j + 1 < count) {
                    swap(nums[j], nums[1 + j]);
                    j++;
                }
                i--;
                count--; 
            }
        }
        return count;
    }
};