class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dpSize = (n * (n + 1)) / 2; // Total size of the flattened triangle
        vector<int> dp(dpSize);

        // Initialize dp with the last row of the triangle
        int start_pos = ((n - 1) * n) / 2; // Start position of the last row
        for (int i = 0; i < triangle[n - 1].size(); ++i) {
            dp[start_pos + i] = triangle[n - 1][i];
        }

        // Process the triangle from bottom to top
        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col < triangle[row].size(); ++col) {
                // Current position in dp
                int curr_pos = (row * (row + 1)) / 2 + col;
                // Calculate the minimum path sum for this position
                int left_child = curr_pos + row + 1;
                int right_child = left_child + 1;
                dp[curr_pos] = triangle[row][col] + min(dp[left_child], dp[right_child]);
            }
        }

        return dp[0]; // The minimum path sum is stored at the top of the triangle
    }
};
