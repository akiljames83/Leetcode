class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Easy solution with map
        unordered_map<char, int> map;
        for (char c : magazine){
            if (map.find(c) != map.end())
                map[c]++;
            else
                map[c] = 1;
        }
        for (char c: ransomNote){
            if (map.find(c) == map.end())
                return false;
            else
            {
                if (!map[c]--)
                    return false;
                
            }
        }
        return true;
    }
};