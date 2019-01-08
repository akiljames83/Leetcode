// Question 476
class Solution {
public:
    int findComplement(int num) {
        int tmp{num};
        int sig{0};
        int res{0};
        while(tmp){
            int bit = tmp & 0x01;
            bit ^= 0x01;
            bit <<= sig;
            res += bit;
            tmp >>= 1;
            sig++;
        }
        
        return res;
    }
};

// Cleaner Version:
class Solution {
public:
    int findComplement(int num) {
        int tmp{num}, sig{0}, res{0};
        while(tmp){
            int bit = (tmp & 0x01) ^ 0x01;
            bit <<= sig++;
            res += bit;
            tmp >>= 1;
        }
        
        return res;
    }
};