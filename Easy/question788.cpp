class Solution {
public:
    bool canRotate(int N){
        bool dif{false};
        while(N){
            int cur = N%10;
            if (cur == 2 || cur == 5 || cur == 6 || cur == 9)
                dif = true;
            else if (cur == 3 || cur == 4 || cur == 7)
                return false;
            N /= 10;
        }
        return dif;
    }
    int rotatedDigits(int N) {
        int count{0};
        for (int i = 1; i <= N; i++)
            if (canRotate(i)) count++;
        return count;
    }
};