class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int sum{};
        for(int i{}; i < nums.size(); i++){
            if(not (i%2)) sum += nums[i];
        }
        return sum;
    }
};