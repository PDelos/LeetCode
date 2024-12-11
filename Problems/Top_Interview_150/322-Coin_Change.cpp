class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        // dp[i] represents min coins needed to make sum i
        vector<int> dp(target + 1, INT_MAX - 1000);
        
        // Base case: 0 coins needed to make sum 0
        dp[0] = 0;
        
        // For each coin, update all possible sums
        for(int coin : coins) {
            for(int sum = coin; sum <= target; sum++) {
                dp[sum] = min(dp[sum], dp[sum - coin] + 1);
            }
        }
        
        // Return result if possible, otherwise -1
        return dp[target] >= INT_MAX - 1000 ? -1 : dp[target];
    }
};
