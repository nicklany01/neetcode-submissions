class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows, then cols, then squares using a hashmap, or set
        for (int i = 0; i < 9; i++) {
            unordered_set<int> row;
            unordered_set<int> col;
            unordered_set<int> square;
            for (int j = 0; j < 9; j++) {
                int r = (i / 3)*3 + (j / 3);
                int c = (i % 3)*3 + (j % 3);
                if (row.contains(board[i][j]) || col.contains(board[j][i]) || square.contains(board[r][c])) return false;
                if (board[i][j] != '.') {
                    row.insert(board[i][j]);
                }
                if (board[j][i] != '.') {
                    col.insert(board[j][i]);
                }
                if (board[r][c] != '.') {
                    square.insert(board[r][c]);
                }
            }
        }
        return true;
    }
};
