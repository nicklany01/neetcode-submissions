class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // dijktra, distance is actually just max value we've come across. we only care about distance to node n-1,n-1
        priority_queue<vector<int>> pq;
        vector<vector<int>> height(grid.size(), vector<int>(grid.size(), 1e9));
        vector<pair<int,int>> neighbors = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        height[0][0] = grid[0][0];
        pq.push({-grid[0][0],0,0});
        while (!pq.empty()) {
            int h = -pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();
            if (r == grid.size()-1 && c == grid.size()-1) return h;
            if (h > height[r][c]) continue;
            for (auto n : neighbors) {
                int newR = r + n.first;
                int newC = c + n.second;
                if (newR >= 0 && newR < grid.size() && newC >= 0 && newC < grid.size()) {
                    int w = max(grid[newR][newC], height[r][c]);
                    if (w < height[newR][newC]) {
                        height[newR][newC] = w;
                        pq.push({-w, newR, newC});
                    }
                }
            }
        }
        cout << height[grid.size()-1][grid.size()-1];
        return 0;
    }
};
