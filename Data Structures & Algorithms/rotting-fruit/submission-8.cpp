class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int result = 0;
        // use multisource bfs
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,pair<int,int>>> pq;
        int freshCount = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    pq.push({0,{r,c}});
                }
                if (grid[r][c] == 1) {
                    freshCount++;
                }
            }
        }
        while (!pq.empty()) {
            int d = pq.front().first;
            int r = pq.front().second.first;
            int c = pq.front().second.second;
            result = max(result, -d);
            pq.pop();
            // for all the neighbors
            vector<pair<int,int>> neighbors = {{0,1},{0,-1},{1,0},{-1,0}};
            for (auto neighbor : neighbors) {
                int newR = r + neighbor.first;
                int newC = c + neighbor.second;
                // check that the neighbor is in bounds, hasnt been visited, and isnt an empty cell
                if (newR < 0 || newR >= rows || newC < 0 || newC >= cols || grid[newR][newC] != 1) continue;
                grid[newR][newC] = 2;
                freshCount--;
                pq.push({d-1,{newR,newC}});
            }
        }
        if (freshCount == 0) return result;
        return -1;
    }
};
