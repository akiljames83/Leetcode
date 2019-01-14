class Solution {
public:
    int binarySearch(vector<int>& nums, int t, int L, int H){
        int mid = (H + L)/2;
        if (nums[mid] == t)
            return mid;
        if (nums[mid] < t)
            return binarySearch(nums, t, L, mid - 1);
        else
            return binarySearch(nums, t, mid + 1, H);
    }
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> snums(nums);
        std::sort(snums.rbegin(), snums.rend());
        vector<string> res;
        
        for (int i = 0; i < nums.size(); i++){
            int pos = binarySearch(snums, nums[i], 0, nums.size() - 1);
            if (pos == 0){
                res.push_back("Gold Medal");
            } else if (pos == 1) {
                res.push_back("Silver Medal");
            } else if (pos == 2){
                res.push_back("Bronze Medal");
            } else {
                res.push_back(to_string(pos+1));
            }
        }
        return res;
    }
};