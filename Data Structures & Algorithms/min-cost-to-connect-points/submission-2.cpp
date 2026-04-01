class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int totalDist = 0;
        vector<vector<int>> edges;
        // add connection to every other node
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist,i,j});
            }
        }
        // kruskal's algorithm to find MST
        unordered_set<int> mst;
        sort(edges.begin(), edges.end());
        // create a disjoint set for each vertex
        // parent[i] gives the index of the parent of i, the parent at the very end is the parent of itself
        // this links everything together
        // size is used so we can always merge a smaller set into a larger one, this keeps the tree shallower
        // i.e. there won't be as long chains and find() operations would be faster
        vector<int> parent(points.size()), size(points.size(),1);
        // init parents so that they are sets containing only themselves
        for (int i = 0; i < points.size(); i++) {
            parent[i] = i;
        }
        // define find function
        function<int(int)> find = [&](int node){
            // while not at the top of the tree/beginning of chain
            if (parent[node] != node) {
                // set parent to parent[parent[node]], also compresses the set/tree
                parent[node] = find(parent[node]);
            }
            return parent[node];
        };
        // go through edges
        // if there are two disconnected sets, add them together, otherwise dont worry
        for (auto edge : edges) {
            int u = find(edge[1]);
            int v = find(edge[2]);
            // they have different parents
            if (u != v) {
                // join the smaller one onto the bigger one
                if (size[u] < size[v]) {
                    swap(u,v);
                }
                parent[v] = u;
                size[u] += size[v];
                // add the distance
                totalDist += edge[0];
            }
        }

        return totalDist;
    }
};
