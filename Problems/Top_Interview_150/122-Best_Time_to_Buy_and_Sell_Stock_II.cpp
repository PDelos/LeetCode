class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        for(int i = 0; i < n-1; i++){
            maxProfit += prices[i+1] - prices[i] > 0 ? prices[i+1] - prices[i] : 0;
        }
        return maxProfit;
    }
};
