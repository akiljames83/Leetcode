#define num(a) (a >= '0') && (a <= '9')

int bounds(bool neg) {
    if (neg) return INT_MIN;
             return INT_MAX;
}

int sign(bool neg, int v){
    if (neg) return -v;
             return v;
}

class Solution {
public:
    int myAtoi(string str) {
        int v = 0;
        bool neg{false}, in{false}, plus{false};
        for (auto i = 0; i < str.size(); i++) {
            if (num(str[i])) {
                in = true;
                if (INT_MAX / 10 >= v) {
                    v = v*10;
                    int n = static_cast<int>(str[i] - '0');
                    if ((INT_MAX - n) < v)
                        return bounds(neg);
                    else
                        v += n;
                } else {
                    return bounds(neg);
                }  
            } else if (str[i] == ' ') {
                if ((neg || plus) and (v == 0)) 
                    return sign(neg, v);
                if (in)
                    return sign(neg, v);
                
            } else if (str[i] == '-') {
                if (neg || plus || in) 
                    return sign(neg, v);
                neg = true;
            } else if (str[i] == '+') {
                if (plus || neg || in) 
                    return sign(neg, v);
                plus = true;
            } else {
                return sign(neg, v);
            }
        }
        
        return sign(neg, v);
    }
};
