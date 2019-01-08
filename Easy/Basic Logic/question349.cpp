class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1{nums1.begin(), nums1.end()};
        unordered_set<int> n2{nums2.begin(), nums2.end()};
        vector<int> res;
        for (auto i : n2){
            if (n1.find(i) != n1.end())
                res.push_back(i);
        }
        return res;
    }
};