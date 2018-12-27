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

// Map version -> 36ms
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> t(20001);
        for(int& i : nums)
            t[i + 10000]++;
        int ans = 0;
        bool evenNum = true;
        for(int j = 0; j < t.size(); ++j){
            while(t[j]){
                if(evenNum)
                    ans+=(j-10000);
                t[j]--;
                evenNum = !evenNum;
            }
        }
        return ans;
    }
};

// O(n) version -> 24ms; based on the paramters of the question -> since the numbers can range from -10000 to 10000 inclusive.
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> t(20001);
        for(int& i : nums)
            t[i + 10000]++;
        int ans = 0;
        bool evenNum = true;
        for(int j = 0; j < t.size(); ++j){
            while(t[j]){
                if(evenNum)
                    ans+=(j-10000);
                t[j]--;
                evenNum = !evenNum;
            }
        }
        return ans;
    }
};