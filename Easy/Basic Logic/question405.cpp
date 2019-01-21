class Solution {
public:
    unordered_map<int, char> i2h {
        {0 , '0'},
        {1 , '1'},
        {2 , '2'},
        {3 , '3'},
        {4 , '4'},
        {5 , '5'},
        {6 , '6'},
        {7 , '7'},
        {8 , '8'},
        {9 , '9'},
        {10 , 'a'},
        {11 , 'b'},
        {12 , 'c'},
        {13 , 'd'},
        {14 , 'e'},
        {15 , 'f'}
    };
    string toHex(int num) {
        bool is_neg{num < 0};
        if (is_neg) num++;
        num = abs(num);
        string res{""};
        if(!num and !is_neg)
            return "0";
        while(num) {
            res += i2h[num % 16];
            num /= 16;
        }
        reverse(res.begin(), res.end());
        if (is_neg)
            return comp2(res);
        return res;
    }
    string comp2(string res) {
        string ret{""};
        for (auto c : res) {
            if (isNum(c))
                ret += i2h[15 - (c - '0')];
            else
                ret += i2h[15 - (c - 'a' + 10)];
        }
        reverse(ret.begin(), ret.end());
        while (ret.length() < 8)
            ret += 'f';
        reverse(ret.begin(), ret.end());
        return ret;  
    }
};