class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        function<void(int,int)> dfs = [&](int x, int y){
            if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] != '1') {
                return;
            }
            grid[x][y] = 'x';
            dfs(x + 1, y);
            dfs(x - 1, y);
            dfs(x, y + 1);
            dfs(x, y - 1);
        };
        int result = 0;
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                if (grid[x][y] == '1') {
                    result++;
                    dfs(x, y);
                }
            }
        }
        return result;
    }
};
