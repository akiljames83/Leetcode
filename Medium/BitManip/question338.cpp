class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        num++;
        for (int i = 0; i < num; i++) {
            int count = 0;
            int n = i;
            while(n){
                if (n & 0x01)
                    count++;
                n >>= 1;
            }
            res.push_back(count);
        }
        return res;
    }
};