class Solution {
private:
    pair<int, int> getSquare(int index, int n) {
        int row = index / n;
        int col = index % n;
        if (row % 2 != 0) col = n - 1 - col;
        return {n - 1 - row, col};
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        queue<int> q;
        vector<int> distance(n * n, -1);

        q.push(0);
        distance[0] = 0;

        while (!q.empty()) {
            int s = q.front(); 
            q.pop();

            for (int i = 1; i <= 6; i++) {
                int new_s = s + i;
                if (new_s >= n * n) continue;

                auto [x, y] = getSquare(new_s, n);
                if (board[x][y] != -1) new_s = board[x][y] - 1;
                if (distance[new_s] != -1) continue;

                distance[new_s] = distance[s] + 1;
                q.push(new_s);
            }
        }
        return distance[n * n - 1];
    }
};
