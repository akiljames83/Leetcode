class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        vector<string> res;
        int m_index{};
        for (int i = 0; i < list1.size();i++)
            map[list1[i]] = i;
        for (int i = 0; i < list2.size(); i++)
            if (map.find(list2[i]) != map.end()) {
                if (res.size() == 0){
                    res.push_back(list2[i]);
                    m_index = i + map[list2[i]];
                } else {
                    if (m_index == i + map[list2[i]]){
                        res.push_back(list2[i]);
                    } else if (m_index > i + map[list2[i]]){
                        res = {};
                        res.push_back(list2[i]);
                        m_index = i + map[list2[i]];
                    }
                }
            }
                
        return res;
    }
};