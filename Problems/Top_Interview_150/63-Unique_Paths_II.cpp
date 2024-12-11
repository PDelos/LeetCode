class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[n-1][m-1] == 1) return 0;
        vector<vector<long long>>dp(n, vector<long long>(m, 0));

        dp[n-1][m-1] = 1;
        for (int i = 1; i < max(n, m); i++) {
            if (i < n && grid[n - 1 - i][m - 1] == 0)
                dp[n - 1 - i][m - 1] = dp[n - i][m - 1]; // Update the last column
            if (i < m && grid[n - 1][m - 1 - i] == 0)
                dp[n - 1][m - 1 - i] = dp[n - 1][m - i]; // Update the last row
        }

        for (int i = n-2; i >=0 ; i--) {
            for(int j = m-2; j >=0; j--){
                if(grid[i][j] == 1) continue;
                dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }

        return dp[0][0];
    }
};
