class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        vector<int> invalid;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]){
                if (invalid.size())
                    return false;
                invalid.push_back(i-1);
            }
        }
        if (!invalid.size())
            return true;
        if (invalid.front() == 0)
            return true;
        if (nums[invalid.front()-1] <= nums[invalid.front()+1])
            return true;
        if (invalid.front() + 2 >= nums.size())
            return true;
        if (nums[invalid.front()] <= nums[invalid.front() + 2])
            return true;
        return false;
    }
};