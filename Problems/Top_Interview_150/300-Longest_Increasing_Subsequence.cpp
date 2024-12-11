class Solution {
private:
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        // dp indicates 

        for(int i=0; i < nums.size(); i++){
            for(int j=0; j < i; j++){
                if(nums[i]>nums[j] && dp[i] < dp[j]+1)
                    dp[i] = dp[j]+1;
            }
        }
        sort(dp.begin(), dp.end());
        return dp[nums.size()-1];


    }
};
