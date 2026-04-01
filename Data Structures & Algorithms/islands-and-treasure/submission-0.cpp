class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF = 2147483647;
        // loop through grid finding each treasure chest
        // for a treasure chest, use dfs to keep searching through tiles where distance is higher, update to be the lower distance
        int rows = grid.size();
        int cols = grid[0].size();
        function<void(int,int,int)> dfs = [&](int r, int c, int d){
            // if it is in the boundaries, and it is a value more than the distance, if it can be traversed, if its the origin
            if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] < 0 || grid[r][c] <= d && d != 0) {
                return;
            }
            grid[r][c] = d;
            dfs(r+1,c,d+1);
            dfs(r-1,c,d+1);
            dfs(r,c+1,d+1);
            dfs(r,c-1,d+1);
        };
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    dfs(r, c, 0);
                }
            }
        }
    }
};