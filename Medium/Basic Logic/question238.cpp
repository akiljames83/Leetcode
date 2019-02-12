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