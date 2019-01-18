class Solution {
public:
    int binary_search(vector<int>&nums, int L, int R, int val) {
        if (L > R)
            return -1;
        int mid = (L + R)/2;
        if (nums[mid] == val)
            return mid;
        if (nums[mid] > val) 
            return binary_search(nums, L, mid - 1, val);
        else
            return binary_search(nums, mid + 1, R, val);
        
    }
    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size() - 1, target);
    }
};