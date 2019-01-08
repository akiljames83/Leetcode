class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) return nums.front();
        unordered_map<int, int>map;
        int size = nums.size()/2;
        for (auto i : nums){
            if (map.find(i) != map.end()){
                if (map[i]++ >= size)
                    return i;
            } else
                map[i] = 1;
        }
        
    }
};

// Use Moore Voting Algorithm !! Well implement