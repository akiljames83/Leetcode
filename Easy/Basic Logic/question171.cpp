class Solution {
public:
    int titleToNumber(string s) {
        int num{0};
        int length{s.size() - 1};
        for (int i = 0; i < s.size(); i++){
            num += pow(26, length--) * (s[i] - 'A' + 1);
        }
        return num;
    }
};