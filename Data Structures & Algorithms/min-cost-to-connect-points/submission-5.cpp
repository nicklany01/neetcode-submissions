class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // create adjacency list
        vector<vector<pair<int,int>>> adj(points.size());
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({-dist, j});
            }
        } 
        int result = 0;
        priority_queue<pair<int,int>> pq;
        vector<bool> visited(points.size(),false);
        pq.push({0, 0});
        int edgesVisited = 0;
        while (!pq.empty() && edgesVisited < points.size()) {
            int d = -pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;

            result += d;
            edgesVisited++;

            for (auto v : adj[u]) {
                if (!visited[v.second]) {
                    pq.push(v);
                }
            }
        }
        return result;
    }
};
