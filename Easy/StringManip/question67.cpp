class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res{""};
        bool carry{false};
        int n = min(a.length(), b.length());
        for (int i = 0; i < n; i++) {
            if (a[i] == '1'){
                if (b[i] == '1') {
                    if (carry) {
                        res += "1";
                    } else {
                        res += "0";
                        carry = true;
                    }
                }
                else {
                    if (carry) {
                        res += "0";
                    } else {
                        res += "1";
                    }
                }     
            } else if (b[i] == '1'){
                if (carry) {
                    res += "0";
                } else {
                    res += "1";
                }
            } else {
                if (carry) {
                    res += "1";
                    carry = false;
                } else {
                    res += "0";
                }
            }
        }
        if (a.length() == b.length()) {
            if (carry)
                res += "1";
            
        } else {
            if (a.length() < b.length())
                a = b;
            for (int i = n; i < a.length(); i++) {
                if (a[i] == '1'){
                    if (carry){
                        res += "0";
                    } else {
                        res += "1";
                    }
                } else {
                    if (carry) {
                        res += "1";
                        carry = false;
                    } else {
                        res += "0";
                    }
                }
            }
            if (carry)
                res += "1";
        }
        reverse(res.begin(), res.end());
        return res;
            
    }
};