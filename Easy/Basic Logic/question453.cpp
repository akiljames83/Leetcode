// Incorrect Solution -> Works but timeout :(
class Solution {
public:
    void addn(vector<int>&nums, int n, int &sum){
        sum += (nums.size()-1)*n;
        for (int i = 0; i < nums.size() - 1;i++)
            nums[i]+= n;
    }
    bool equal(vector<int>&nums, int sum){
        if ((nums.front() == nums.back()) and (nums.front() == int(sum/nums.size())))
            return true;
        return false;
    }
    int tsum(vector<int>&nums){
        int t{0};
        for (int i = 0; i < nums.size(); i++)
            t += nums[i];
        return t;
    }
    int minMoves(vector<int>& nums) {
        int count{0};
        int sum = tsum(nums);
        std::sort(nums.begin(), nums.end());
        while(!equal(nums, sum)){
            //cout << "hit" << endl;
            int dif = nums.back() - nums.front();
            addn(nums, dif, sum);
            count += dif;
            std::sort(nums.begin(), nums.end());
        }
        return count;
    }
};