class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        function<void(int,int)> dfs = [&](int r, int c) {
            // if its not in the bounds of the grid and its not unvisited land
            if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 1) {
                return;
            }
            count++;
            grid[r][c] = 2;
            dfs(r+1,c);
            dfs(r-1,c);
            dfs(r,c+1);
            dfs(r,c-1);
        };
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    count = 0;
                    dfs(r, c);
                    result = max(result, count);
                }
            } 
        } 
        return result;
    }
};
