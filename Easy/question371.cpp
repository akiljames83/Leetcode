class Solution {
public:
    int getSum(int a, int b) {
        while(a){
            int carry = a & b;
            b = a ^ b;
            a = carry << 1;
        }
        return b;
    }
};