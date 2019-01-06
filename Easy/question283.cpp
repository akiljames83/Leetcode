class Solution {
public:
    void swap(vector<int>& nums, int fst, int snd){
        int tmp = nums[snd];
        nums[snd] = nums[fst];
        nums[fst] = tmp;
    }
    void moveZeroes(vector<int>& nums) {
        int top{0};
        bool reg = true;
        for (int i = 0; i < nums.size() - 1; i++){
            if (reg) top++;
            if (!nums[i]){
                if (nums[i+1])
                    swap(nums, i, i+1);
                else{
                    reg = false;
                    for (int j = top; j < nums.size(); j++){
                        top = j;
                        if (nums[j])
                            break;
                    }
                    if(!nums[top]) break;
                    swap(nums, i, top);
                }
            }
        }
    }
};