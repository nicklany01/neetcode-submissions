class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows, then cols, then squares using a hashmap, or set, or more optimally a bitset
        for (int i = 0; i < 9; i++) {
            uint16_t row = 0;
            uint16_t col = 0;
            uint16_t square = 0;
            for (int j = 0; j < 9; j++) {
                int r = (i / 3)*3 + (j / 3);
                int c = (i % 3)*3 + (j % 3);
                if (row & (1 << (board[i][j] - '0')) || col & (1 << (board[j][i] - '0')) || square & (1 << (board[r][c] - '0'))) return false;
                if (board[i][j] != '.') {
                    row |= 1 << (board[i][j] - '0');
                }
                if (board[j][i] != '.') {
                    col |= 1 << (board[j][i] - '0');
                }
                if (board[r][c] != '.') {
                    square |= 1 << (board[r][c] - '0');
                }
            }
            cout << row;
        }
        return true;
    }
};
