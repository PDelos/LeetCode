class Solution {
private: 
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int n, m;

    void dfs(vector<vector<char>>& board, int r, int c) {
        if(board[r][c]=='#') return;
        board[r][c]='#';

        for(auto d : dirs){
            int new_r = r+d[0];
            int new_c = c+d[1];

            if(new_r >= m || new_c >= n) continue;
            if(new_r < 0 || new_c < 0) continue;
            if(board[new_r][new_c] == 'O')
                dfs(board,  new_r, new_c);
        }
        return;
    } 

public:
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();

        for (int r = 0; r < m; r++) {
            if (board[r][0] == 'O') dfs(board, r, 0);
            if (board[r][n - 1] == 'O') dfs(board, r, n - 1);
        }
        for (int c = 0; c < n; c++) {
            if (board[0][c] == 'O') dfs(board, 0, c);
            if (board[m - 1][c] == 'O') dfs(board, m - 1, c);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = board[i][j]=='#' ? 'O' : 'X';
            }
        }
        return;
    }
};
