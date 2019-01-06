// O(N) Time O(N) Space
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (!nums.size()) return {};
        vector<int> res;
        int arr [nums.size()]{0};
        for (int i = 0; i < nums.size(); i++){
            arr[nums[i]-1] = 1;
        }
        for (int i = 0; i < nums.size(); i++){
            if (!arr[i]) res.push_back(i+1);
        }
        return res;
    }
};

// O(N) Time O(1) Space!!
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (!nums.size()) return {};
        vector<int> res;
        for (auto i : nums){
            if (nums[abs(i)-1] > 0) {
                nums[abs(i)-1] *= -1
            }
        }
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};