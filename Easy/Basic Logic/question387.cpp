class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> map(26,0);
        for (char c : s){
            map[c - 'a']++;
            
        }
        int i{};
        for (char c : s){
            if (!(--map[c - 'a'])++)
                return i;
            i++;
        }
        return -1;
    }
};