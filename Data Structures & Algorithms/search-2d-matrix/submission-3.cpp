class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int row_len = matrix.size();
        int col_len = matrix[0].size();
        int r = col_len * row_len - 1;
        // just use a flattened array
        while (l <= r) {
            int m = l + (r - l) / 2;
            int val = matrix[m / col_len][m % col_len];
            if (val == target) {
                return true;
            } else if (val > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return false;
    }
};
