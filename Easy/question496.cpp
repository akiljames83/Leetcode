class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int,int> index;
        int max_pos = nums.size();
        for (int i = 0; i < max_pos; i++) {
            index[nums[i]] = i;
        }
        for(int i = 0; i < findNums.size(); i++){
            int n = findNums[i];
            int pos = index[n] + 1;
            
            while(pos < max_pos) {
                if (nums[pos++] > n){
                    findNums[i] = nums[--pos];
                    break;
                }
            }
            if (findNums[i] == n) findNums[i] = -1;
        }
        return findNums;
    }
};