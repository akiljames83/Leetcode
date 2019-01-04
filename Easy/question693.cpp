class Solution {
public:
    bool hasAlternatingBits(int n) {
        int first = n & 1;
        n >>= 1;
        while(n){
            if ((n & 1) != first)
                first = !first;
            else 
                return false;
            n >>= 1;
        }
        return true;
    }
};