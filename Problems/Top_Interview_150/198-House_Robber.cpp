class Solution {
private:
    vector<int> dp; // dp[pos] stores the maximum money that can be robbed starting from house pos

    int robHouse(vector<int>& nums, int pos) {
        if (pos >= nums.size()) {
            return 0; // No houses left to rob
        }
        if (dp[pos] != -1) {
            return dp[pos]; // Return cached result
        }

        // Rob the current house and skip the next one, or skip the current house
        dp[pos] = max(nums[pos] + robHouse(nums, pos + 2), robHouse(nums, pos + 1));
        return dp[pos];
    }

public:
    int rob(vector<int>& nums) {
        dp = vector<int>(nums.size(), -1); // Initialize dp array with -1
        return robHouse(nums, 0); // Start from the first house
    }
};
