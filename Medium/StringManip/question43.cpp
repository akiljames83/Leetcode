class Solution {
public:
    string add(string num1, string num2) {
        int carry = 0;
        string res = "";
        for (int i = 0; i < min(num1.size(), num2.size()); i++) {
            int cur = (num1[i] - '0') + (num2[i] - '0') + carry;
            carry = cur / 10;
            res += to_string(cur % 10);
        }
        if (num1.size() > num2.size()) {
            for (int i = num2.size(); i < num1.size(); i++) {
                int cur = (num1[i] - '0') + carry;
                carry = cur/10;
                res += to_string(cur % 10);
            }
        } else {
            for (int i = num1.size(); i < num2.size(); i++) {
                int cur = (num2[i] - '0') + carry;
                carry = cur/10;
                res += to_string(cur % 10);
            }
        }
        if (carry)
            res += "1";
        return res;
    }
    string remove(string num1) {
        while (num1.back() == '0'){
            num1 = num1.substr(0,num1.size() - 1);
        }
        return num1;
    }
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<string> nums;
        int carry = 0;
        string cur = "";
        
        for (int i = 0; i < num1.size(); i++) {
            for (auto btm : num2) {
                int tmp = (num1[i]-'0') * (btm-'0') + carry;
                carry = tmp / 10;
                tmp %= 10;
                cur += to_string(tmp);
            }
            if (carry) cur += to_string(carry);
            
            nums.push_back(cur);
            reverse(cur.begin(), cur.end());
            cur = string(i+1, '0');
            carry = 0;
        }
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = add(nums[i], nums[i-1]);
        }
        string res = remove(nums.back());
        reverse(res.begin(), res.end());
        if (!res.size())
            return "0";
        return res;
    }
};