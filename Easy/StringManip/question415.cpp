class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string fs{""};
        int carry{};
        int length{min(num1.length(), num2.length())};
        for (int i = 0; i < length; i++) {
            int n1 = num1[i] - '0';
            int n2 = num2[i] - '0';
            if (n1 + n2 + carry >= 10){
                //carry = 1;
                int f = (n1 + n2 + carry) % 10;
                fs += to_string(f);
                carry = 1;
                //cout << "hit " << fs << endl;
            } else {
                fs += to_string(n1 + n2 + carry);
                carry = 0;
            }
        }
        if (num1.length() > num2.length()) {
            for (int i = length; i < num1.length(); i++) {
                int n1 = num1[i] - '0';
                if (carry + n1 >= 10) {
                    int f = (n1 + carry) % 10;
                    carry = 1;
                    fs += to_string(f);
                } else {
                    fs += to_string(n1 + carry);
                    carry = 0;
                }
            }
        } else if (num1.length() < num2.length()) {
            for (int i = length; i < num2.length(); i++) {
                int n1 = num2[i] - '0';
                if (carry + n1 >= 10) {
                    int f = (n1 + carry) % 10;
                    carry = 1;
                    fs += to_string(f);
                } else {
                    fs += to_string(n1 + carry);
                    carry = 0;
                }
            }
        } 
        if (carry)
            fs += '1';
        reverse(fs.begin(), fs.end());
        return fs;
    }
};