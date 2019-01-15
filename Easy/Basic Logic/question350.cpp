class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> res;
        for (auto i : nums1){
            if (map.find(i) != map.end()){
                map[i]++;
            } else {
                map[i] = 1;
            }
        }
        for (auto i : nums2){
            if (map.find(i) != map.end()){
                res.push_back(i);
                if (!--map[i])
                    map.erase(i);
            }
        }
        return res;
    }
};