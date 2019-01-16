class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() == 3) return nums[0]*nums[2]*nums[1];
        vector<int> great;
        vector<int> least;
        bool has_zero = false;
        for (auto i : nums){
            if (i > 0) {
                if (!great.size())
                    great.push_back(i);
                else if (great.size() < 3){
                    if (i > great.front())
                        great.insert(great.begin(), i);
                    else if (i > great[1])
                        great.insert(great.begin()+1,i);
                    else
                        great.emplace_back(i);
                } else {
                    for (int j = 0; j < great.size(); j++) {
                        if (i > great[j]) {
                            great.insert(great.begin()+j,i);
                            great.pop_back();
                            break;
                        }
                            
                    }
                }
            }
            else if (i == 0)
                has_zero = true;
            else {
                if (!least.size())
                    least.push_back(i);
                else if (least.size() < 3){
                    if (i < least.front())
                        least.insert(least.begin(), i);
                    else if (i < least[1])
                        least.insert(least.begin()+1,i);
                    else
                        least.emplace_back(i);
                } else {
                    for (int j = 0; j < least.size(); j++) {
                        if (i < least[j]) {
                            least.insert(least.begin()+j,i);
                            least.pop_back();
                            break;
                        }
                    }
                }
            }

        }
        int from_neg = -INT_MAX;
        int from_pos = from_pos;
        if (least.size() >= 2 and great.size()) 
            from_neg = least[0]*least[1]*great[0];
    
        if (great.size() == 3)
            from_pos = great[0]*great[1]*great[2];
        
        if ((!great.size() and has_zero) or (great.size() + least.size() < 3))
            return 0;
        
        if (from_neg == from_pos and from_pos == -INT_MAX){
            int tot{1};
            for (int i = great.size() - 1; i >= 0; i--)
                tot *= great[i];
            return tot*least.back();
        }
        
        return (from_neg > from_pos ? from_neg : from_pos);
        
    }
};