class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            int k = nums.size() - 1;
            for (int j = i+1; j < nums.size(); j++) {
                int cur = -1 * (nums[i] + nums[j]);
                while(cur < nums[k] and k > i and k > j) {
                    k--;
                }
                if (k == i || k == j)
                    break;
                if (cur == nums[k]) {
                    res.push_back({nums[i], nums[j], nums[k]});
                }
                while (j + 1 < nums.size())
                    if (nums[j] == nums[j+1])
                        j++;
                    else
                        break;
            }
            while (i + 1 < nums.size())
                if (nums[i] == nums[i+1])
                    i++;
                else
                    break;
        }
        return res;
    }
};