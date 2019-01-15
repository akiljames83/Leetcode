#define isLow(c) ((c >= 'a') and (c <= 'z'))
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> map(52,0);
        for (auto c : s) {
            if (isLow(c))
                map[c-'a']++;
            else
                map[c-'A'+26]++;
        }
        bool single{false};
        int count{}, max{};
        for (auto i : map){
            if (!(i%2))
                count += i;
            else {
                if (!single)
                    single = true;
                count += i - 1;
            }
        }
        if (single)
            count++;
        return count;
    }
};