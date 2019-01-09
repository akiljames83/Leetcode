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