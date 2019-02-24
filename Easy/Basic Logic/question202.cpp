class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while (n != 1) {
            if (set.find(n) != set.end()){
                return false;
            }
            set.insert(n);
            int sum{0};
            while (n) {
                int m = (n % 10);
                sum += m*m;
                n/=10;
            }
            n = sum;
        }
            
        return true;
    }
};