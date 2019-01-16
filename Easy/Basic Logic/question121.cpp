class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size())
            return 0;
        pair<int, int> low = make_pair(0,prices[0]);
        int profit{};
        for(int i = 1; i < prices.size(); i++){
            if (prices[i] > low.second){
                if (profit < prices[i] - low.second) {
                    profit = prices[i] - low.second;
                }
            }
            if (prices[i] < low.second) {
                low = make_pair(i, prices[i]);
            }
        }
        return profit;
        
    }
};