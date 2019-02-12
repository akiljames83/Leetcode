// O(N) Time; O(1) Space:
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res = nums;

        // Go to right
        for (int i = 1; i < nums.size(); i++)
            res[i] *= res[i-1];
        
        // tracker for the left direction
        int t = 1;
        for (int i = nums.size() - 1; i > 0; i--) {
            // essentially multiplying left side and right side
            res[i] = res[i-1]*t;
            t *= nums[i];
        }
        res[0] = t;
        
        return res;
            
    }
};

// O(N) Time and Space:
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>front = nums;
        vector<int>back = nums;
        vector<int>res = nums;(nums.size(), 0);

        for (int i = 1; i < nums.size(); i++)
            front[i] *= front[i-1];
        
        for (int i = nums.size()-2; i >= 0; i--)
            back[i] *= back[i+1];
        
        for (int pos = 0; pos < nums.size(); pos++) {
            if (!pos)
                res[pos] = back[pos+1];
            else if (pos == nums.size() - 1)
                res[pos] = front[pos-1];
            else {
                res[pos] = front[pos-1]*back[pos+1];
            }
        }
        return res;
            
    }
};