class Solution {
public:
    unordered_set<int> PRIMES = {2,3,5,7,11,13,17,19,23};
    bool isPrime(int num){
        if (PRIMES.find(num) != PRIMES.end())
            return true;
        else 
            return false;
    }
    int countPrimeSetBits(int L, int R) {
        int count{0};
        for (int i = L; i <= R; i++){
            int tmp = i;
            int bits{0};
            while(tmp){
                if (tmp & 0x01) bits++;
                tmp >>= 1;
            }
            if (isPrime(bits)) count++;
        }
        return count;
    }
};