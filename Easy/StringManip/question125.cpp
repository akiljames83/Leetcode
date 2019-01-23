#define isAlph(c) (((c >= 'a') and (c <= 'z')) or ((c >= 'A') and (c <= 'Z')))
#define isNum(c) ((c >= '0') and (c <= '9'))
class Solution {
public:
    bool isPalindrome(string s) {
        if (!s.size())
            return true;
        string p{""};
        for (auto c : s) {
            if (isAlph(c)){
                p += tolower(c);
            } else if (isNum(c)) {
                p += c;
            }
        }
        //cout << p << endl;
        for (int i = 0, j = p.length() - 1; i < p.length(); i++, j--) {
            if (i == j)
                return true;
            if (i > j)
                break;
            if (p[i] != p[j])
                return false;
        }
        return true;
    }
};