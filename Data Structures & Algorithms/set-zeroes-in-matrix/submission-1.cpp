class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        // track whether there is a zero in the first row or column
        int row = false;
        int col = false;
        for (int r = 0; r < rows; r++) {
            if (matrix[r][0] == 0) {
                row = true;
            } 
        }
        for (int c = 0; c < cols; c++) {
            if (matrix[0][c] == 0) {
                col = true;
            }
        }
        // use first row to track cols, and first col to track rows
        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }
        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                if (matrix[r][0] == 0 || matrix[0][c] == 0) {
                    matrix[r][c] = 0;
                    cout << r << c << endl;
                }
            }
        }
        if (row) {
            for (int r = 0; r < rows; r++) {
                matrix[r][0] = 0;
            }
        }
        if (col) {
            for (int c = 0; c < cols; c++) {
                matrix[0][c] = 0;
            }
        }
    }
};
