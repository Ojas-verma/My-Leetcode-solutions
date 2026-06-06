class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size();
        int n = board[0].size();

        // Base cases
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
            return;

        // Mark boundary-connected O's
        board[i][j] = '#';

        // Explore 4 directions
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        if (m == 0 || n == 0) return;

        // Check first and last columns
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);

            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }

        // Check first and last rows
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);

            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j);
        }

        // Convert surrounded O's to X
        // Restore marked cells back to O
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};