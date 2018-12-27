#include <cmath>
auto __=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool check(int original){
        int num = original;
        int temp{num%10};
        int itr = static_cast<int>(log10 (static_cast<double>(original))) + 2;
        while( itr-- != 0) {
            if ((temp == 0) || (original % temp)) return false;
            temp = num%10;
            num /= 10;
        } 
        return true;
    }
    /*
        int original = num;
        int digit;
        while(num > 0){
            digit = num % 10;
            if(digit == 0 || original % digit != 0)
                return false;
            num /= 10;
        }
    */
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            if (check(i)) ans.push_back(i);
        }
        return ans;
    }
};