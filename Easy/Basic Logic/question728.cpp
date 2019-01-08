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
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            if (check(i)) ans.push_back(i);
        }
        return ans;
    }
};

//  Faster Solution: Same logic but implemented properly
class Solution {
public:
    bool check(int original){
        int num = original;
        while( num != 0) {
            int temp{num%10};
            if ((temp == 0) || (original % temp)) return false;
            num /= 10;
        } 
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            if (check(i)) ans.push_back(i);
        }
        return ans;
    }
};