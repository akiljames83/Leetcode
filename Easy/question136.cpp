// Bit Manipulation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++){
            res ^= nums[i];
        }
        return res;
    }
};

// Set:
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++){
        	int cur = nums[i];
            if (set.find(cur) != set.end())
            	set.erase(cur);
            else set.insert(cur);
        }
        return *set.begin();
    }
};