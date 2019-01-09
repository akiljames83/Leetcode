class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (auto n : nums){
            if (set.find(n) == set.end())
                set.insert(n);
            else
                return true;   
        }
        return false;
    }
};

// Clean and Fast Solution:
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Sort the vector. Need for std::unique to work.
        sort(nums.begin(), nums.end());
        
        // Collect all the unique values to the front.
        auto it = unique(nums.begin(), nums.end());
        
        // Return result.
        return ((it == nums.end()) ? false : true);
    }
};