class Solution {
private:
    string _word;
    vector<vector<char>> _board;
    vector<vector<bool>> visited;
    vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool isValid(int pos, int x, int y) {
        int n = _board.size();
        int m = _board[0].size();

        if (x < 0 || y < 0 || x >= n || y >= m) return false;
        if (visited[x][y]) return false;
        if (_board[x][y] != _word[pos]) return false;
        return true;
    }

    bool wordSearch(int pos, int x, int y) {
        if (pos == _word.size() - 1) return true;

        for (auto& move : moves) {
            int new_x = x + move[0];
            int new_y = y + move[1];
            if (!isValid(pos + 1, new_x, new_y)) continue;
            visited[new_x][new_y] = true;
            if(wordSearch(pos + 1, new_x, new_y)) 
                return true;
            visited[new_x][new_y] = false;
        }
        
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        _word = word;
        _board = board;
        int n = board.size(), m = board[0].size();

        visited.resize(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (wordSearch(0, i, j)) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};
