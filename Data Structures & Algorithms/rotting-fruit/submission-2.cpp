class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int result = 0;
        // use multisource bfs
        int rows = grid.size();
        int cols = grid[0].size();
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int freshCount = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    visited[r][c] = 1;
                    pq.push({0,{r,c}});
                }
                if (grid[r][c] == 1) {
                    freshCount++;
                }
            }
        }
        while (!pq.empty()) {
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            result = max(result, -d);
            pq.pop();
            // for all the neighbors
            vector<pair<int,int>> neighbors = {{0,1},{0,-1},{1,0},{-1,0}};
            for (auto neighbor : neighbors) {
                int newR = r + neighbor.first;
                int newC = c + neighbor.second;
                // check that the neighbor is in bounds, hasnt been visited, and isnt an empty cell
                if (newR < 0 || newR >= rows || newC < 0 || newC >= cols || visited[newR][newC] || grid[newR][newC] != 1) continue;
                visited[newR][newC] = 1;
                freshCount--;
                pq.push({d-1,{newR,newC}});
            }
        }
        if (freshCount == 0) return result;
        return -1;
    }
};
