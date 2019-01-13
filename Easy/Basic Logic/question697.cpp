class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (!nums.size())
            return 0;
        unordered_map<int, vector<int>> map; // int [3]
        int deg{1};
        for( int i = 0; i < nums.size(); i++){
            if (map.find(nums[i]) == map.end()){
                map[nums[i]] = {i,i,1};
            }
            else {
                map[nums[i]][1] = i;
                if (++map[nums[i]][2] > deg)
                    deg = map[nums[i]][2];
            }
        }
        int dist = INT_MAX;
        for (auto it : map){
            if ((it.second)[2] == deg){
                int t_d = (it.second)[1] - (it.second)[0];
                if (t_d < dist)
                    dist = t_d;
            }
        }
        return dist + 1;
        
    }
};