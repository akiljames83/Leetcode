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

// Using a vector instead of a hashtable: O(N) beats 99.51%;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Easy solution with map
        vector<int> map(256,0);
        for (char c : magazine)
            map[static_cast<int>(c)]++;
        
        for (char c: ransomNote)
            if (!map[static_cast<int>(c)]--)
                return false;

        return true;
    }
};