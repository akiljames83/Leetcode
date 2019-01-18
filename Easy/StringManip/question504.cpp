#include <sstream>
class Solution {
public:
    string convertToBase7(int num) {
        if (!num) 
            return "0";
        stringstream ss;
        bool is_neg{num < 0};
        bool is_divis{!num%7};
        num = abs(num);
        while(num) {
            int cur = num % 7;
            ss << cur;
            num /= 7;
        }
        if (is_neg)
            ss << '-';
        string res = ss.str();
        std::reverse(res.begin(), res.end());
        return res;
    }
};