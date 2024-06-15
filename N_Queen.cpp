class Solution {
public:
    bool possible(int row, int col, const vector<vector<string>>& board) {
        int n = board.size();

        // Check for queens in the same row
        for (int i = 0; i < col; i++) {
            if (board[row][i] == "Q") return false;
        }

        // Check for queens in the upper left diagonal
        for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
            if (board[r][c] == "Q") return false;
        }

        // Check for queens in the lower left diagonal
        for (int r = row + 1, c = col - 1; r < n && c >= 0; r++, c--) {
            if (board[r][c] == "Q") return false;
        }

        return true;
    }

    void solve(int col, int n, vector<vector<string>>& board, vector<vector<string>>& ans) {
        if (col >= n) {
            vector<string> solution;
            for (int i = 0; i < n; i++) {
                string row = "";
                for (int j = 0; j < n; j++) {
                    row += board[i][j];
                }
                solution.push_back(row);
            }
            ans.push_back(solution);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (possible(row, col, board)) {
                board[row][col] = "Q";
                solve(col + 1, n, board, ans);
                board[row][col] = ".";
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<vector<string>> ans;
        solve(0, n, board, ans);
        return ans;
    }
};
