class Solution {
public:
    string convertToTitle(int n) {
        string res{""};
        while(n) {
            int c = (n % 26);
            if (!c) {res += 'Z';n/=27;}
            else {res += ('A' + c - 1); (n/=26);}
        }
        reverse(res.begin(), res.end());
        return res;
    }
};