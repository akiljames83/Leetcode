class Solution {
public:
    int fib(int N) {
        if (N == 0)
            return 0;
        if (N == 1)
            return 1;
        vector<int> past (N,0);
        past[0] = 0;
        past[1] = 1;
        
        for(int i = 2; i < N; i++){
            past[i] = past[i-1] + past[i-2];
        }
        return past[N-1]+past[N-2];
    }
};
