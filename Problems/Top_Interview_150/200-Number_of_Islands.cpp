class Solution {
private:
    int movement[4][2] = {{0, 1},{1, 0},{-1, 0},{0, -1}};
    int n, m;

    void dfs(vector<vector<char>>& grid, int i, int j){
        // first of all change to a non used character
        grid[i][j] = '.';

        for(auto x : movement){
            int new_i = i + x[0];
            int new_j = j + x[1];

            if(new_i >= m || new_j >= n) continue;
            if(new_i < 0 || new_j < 0) continue;
            if(grid[new_i][new_j] == '1') 
                dfs(grid,new_i, new_j);
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        m = grid.size(), n = grid[0].size();

        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '1') {
                    ++count;
                    dfs(grid, i , j);
                }
            }
        }

        return count;
    }
};
