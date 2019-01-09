class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) 
            return 0;
        int profit{0};
        int clow{prices[0]};
        for(int i = 0; i < prices.size() - 1; i++){
            if (prices[i] < clow){
                clow = prices[i];
            } else if (prices[i] > clow){
                if (prices[i + 1] <= prices[i]){
                    profit += prices[i] - clow;
                    clow = INT_MAX;
                }
            }
        }
        profit += (prices.back() - clow > 0) ? (prices.back() - clow) : 0;
        return profit;
    }
};