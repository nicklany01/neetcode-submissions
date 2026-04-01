class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        priority_queue<pair<int,pair<int,int>>> pq;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    visited[r][c] = 1;
                    pq.push({0, {r,c}});
                }
            }
        }
        // classic bfs
        while (!pq.empty()) {
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            grid[r][c] = -d;
            // add neighbors
            vector<pair<int,int>> neighbors = {{0,1},{0,-1},{1,0},{-1,0}}; 
            for (auto neighbor : neighbors) {
                int newR = r + neighbor.first;
                int newC = c + neighbor.second;
                // if out of bounds or untraversable
                if (newR < 0 || newR >= rows || newC < 0 || newC >= cols || grid[newR][newC] < 0) continue;
                if (visited[newR][newC] == 0) {
                    visited[newR][newC] = 1;
                    pq.push({d-1, {newR,newC}});
                }
            }
        }
    }
};