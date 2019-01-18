class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size())
            return 0;
        int prev{nums[0]};
        int count_dub{0};
        int len = nums.size() - 1;
        int rlen = len + 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == prev) {
                if (++count_dub >= 2) {
                    nums[i] = INT_MIN;
                    rlen--;
                }
            } else {
                count_dub = 0;
                prev = nums[i];
            }
        }
        int back = len;
        for (int i = 0; i < len; i++) {
            if (nums[i] == INT_MIN) {
                nums[i] = nums[back];
                nums[back--] = INT_MAX;
            } 
            while(nums[i] == INT_MIN) {
                nums[i] = nums[back];
                nums[back--] = INT_MAX;
                if (i == rlen)
                    break;
            }
        }
        std::sort(nums.begin(), nums.begin()+rlen);
        return rlen;
    }
};

// MUCH Cleaner solution:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(index<2 || nums[index-2] != nums[i])
                swap(nums[index++], nums[i]);
        }
        return index;
    }
};