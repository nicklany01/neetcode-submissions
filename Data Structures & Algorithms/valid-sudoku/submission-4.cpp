class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows, then cols, then squares using a hashmap, or set, or more optimally a bitset
        uint16_t rows[9] = {0};
        uint16_t cols[9] = {0};
        uint16_t squares[9] = {0};
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                int val = board[r][c] - '0';
                // put into right bucket
                if (rows[r] & 1 << val || cols[c] & 1 << val || squares[(r/3)*3 + (c/3)] & 1 << val) return false;
                rows[r] |= 1 << val;
                cols[c] |= 1 << val;
                squares[(r / 3)*3 + (c / 3)] |= 1 << val;
            }
        }
        return true;
    }
};
