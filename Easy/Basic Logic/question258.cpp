class Solution {
public:
    int addDigits(int num) {
        if (num < 10) return num;
        int ret{0};
        while(num){
            ret += num%10;
            num/=10;
        }
        return addDigits(ret); 
    }
};

// Constant time solution:
class Solution {
public:
    int addDigits(int num) {
        return (num % 9 or !num) ? num%9 : 9;
    }
};