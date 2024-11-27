class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int currentProfit = 0;
        for(int i = 0; i < n-1; i++){
            if(currentProfit < 0) 
                currentProfit = 0;
            
            currentProfit += prices[i+1] - prices[i];

            if(maxProfit < currentProfit) 
                maxProfit = currentProfit;
        }
        return maxProfit;
    }
};
