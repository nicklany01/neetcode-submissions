class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int cols = matrix[0].size();
        int rows = matrix.size();
        vector<int> result;
        int sc = 0, sr = 0;
        while (result.size() != matrix[0].size()*matrix.size()) {
            cout << "sr: " << sr << ", sc: " << sc << ", rows: " << rows << ", cols: " << cols << ", result size: " << result.size() << endl;
            for (int c = sc; c < cols; c++) {
                result.push_back(matrix[sr][c]);
            }
            sr++;
            for (int r = sr; r < rows; r++) {
                result.push_back(matrix[r][cols-1]);
            }
            cols--;
            if (result.size() == matrix[0].size()*matrix.size()) break;
            for (int c = cols - 1; c >= sc; c--) {
                result.push_back(matrix[rows-1][c]);
            }
            rows--;
            for (int r = rows - 1; r >= sr; r--) {
                result.push_back(matrix[r][sc]);
            }
            sc++;
        }
        return result;
    }
};
