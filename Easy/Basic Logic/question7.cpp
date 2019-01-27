class Solution {
public:
    int reverse(int x) {
        if (x < 10 and x > -10)
            return x;
        //cout << INT_MIN << endl;
        if (x == INT_MIN)
            return 0;
        bool neg{x < 0};
        x = abs(x);
        int num{0};
        int fpos{x % 10};
        int count{};
        while(x){
            int n = x % 10;
            if (count == 9) {
                if (num > INT_MAX/10)
                    return 0;
                if (num == INT_MAX/10 and n > 7)
                    return 0;
            }
                
            num = num*10 + n;
            x /= 10;
            count++;
        }
        //cout << count << endl;
        if (neg)
            num *= -1;
        return num;
    }
};