class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count{};
        while (n){
            if (n & 0x01)
                count++;
            n >>= 1;
        }
        return count;
    }
};