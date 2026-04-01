class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // do bfs
        queue<pair<int,int>> q;
        int grid_height = grid.size();
        int grid_width = grid[0].size();
        vector<vector<int>> visited(grid_height, vector<int>(grid_width, 0));
        function<void(int,int)> bfs = [&](int y, int x){
            vector<pair<int,int>> neighbours = {{0,1}, {0,-1}, {1,0}, {-1,0}};
            for (auto neighbour : neighbours) {
                int newY = y + neighbour.second;
                int newX = x + neighbour.first;
                if (newX >= 0 && newX < grid_width && newY >= 0 && newY < grid_height
                && grid[newY][newX] == '1' && visited[newY][newX] == 0) {
                    visited[newY][newX] = 1;
                    q.push({newY,newX});
                }
            }
        };
        // keep looping through and finding unvisited node
        int result = 0;
        int grid_size = grid_width * grid_height;
        for (int i = 0; i < grid_size; i++) {
            int y = i / grid_width;
            int x = i % grid_width;
            // do bfs on the unvisited node to find the connected nodes and increment counter
            if (grid[y][x] == '1' && visited[y][x] == 0) {
                visited[y][x] = 1;
                q.push({y,x});
                result++;
            }
            while(!q.empty()) {
                auto pos = q.front();
                q.pop();
                bfs(pos.first, pos.second);
            }
        }
        return result;
    }
};
