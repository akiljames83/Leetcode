class Solution {
public:
    string reverseStr(string s, int k) {
        if (k == 1) return s;
        bool flip = true;
        for (int i = 0; i < s.size(); i++) {
            if (!((i + 1) % k)) {
                if (flip) {
                    int l = i + 1 - k;
                    int r = i;
                    while (l < r){
                        char tmp = s[r];
                        s[r--] = s[l];
                        s[l++] = tmp;
                    }
                    flip = false;
                } else 
                    flip = true;
            }
            if (i + 1 == s.size() and ((i + 1) % k) and flip) {
                int l = i + 1 - ((i + 1) % k);
                int r = i;
                while (l < r) {
                    char tmp = s[r];
                    s[r--] = s[l];
                    s[l++] = tmp;
                }
                break;
            }
        }
        return s;
    }
};