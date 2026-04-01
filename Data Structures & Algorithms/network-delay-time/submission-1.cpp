class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // dijkstra
        // create adjacency list: adj[ui] = {vi, ti}
        vector<vector<pair<int,int>>> adj(n+1);
        for (auto edge : times) {
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        // set distances
        vector<int> dist(n+1,1e9);
        dist[0] = 0; // nodes range from 1 to n, so don't care about this
        dist[k] = 0;
        // prepare min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        // dijkstra relax edges
        while(!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            // skip since a smaller distance has already been found
            if (d > dist[u]) {
                continue;
            }
            for (auto edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                // shorter path has been found, relax edge (update dist)
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxDist = 0;
        for (auto d : dist) {
            cout << d << endl;
            maxDist = max(maxDist, d);
        }
        return maxDist != 1e9 ? maxDist : -1;
    }
};
