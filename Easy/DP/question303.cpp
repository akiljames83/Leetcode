class NumArray {
public:
    vector<int> sum = {0};
    NumArray(vector<int>& nums) {
        for(auto n : nums)
            sum.push_back(n + sum.back());
    }
    
    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }
};