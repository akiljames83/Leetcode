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