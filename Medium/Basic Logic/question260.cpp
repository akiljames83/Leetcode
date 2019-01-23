class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        for (auto n: nums){
            if (set.find(n) == set.end()) {
                // does not exist
                set.insert(n);
            } else {
                set.erase(n);
            }
        }
        return {*set.begin(), *++(set.begin())};
    }
};

// BEAUTIFUL SOLUTION: Explanation from: https://leetcode.com/terrancepyrope/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int aXorB = 0;
        for (int num : nums) {
            aXorB ^= num;
        }
        int differingBit = 1;
        while ((differingBit & aXorB) == 0) {
            differingBit <<= 1;
        }
        
        int a = 0;
        int b = 0;
        for (int num : nums) {
            if ((num & differingBit) == 0) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return {a, b};
    }
};