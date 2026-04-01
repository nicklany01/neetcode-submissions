class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<bool>> adj(26,vector<bool>(26, false));
        vector<bool> nodes(26, false);
        vector<int> inDegree(26, 0);
        queue<int> q;
        // create graph
        for (auto word : words) {
            for (auto c : word) {
                nodes[c - 'a'] = true; 
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            // find the first difference in chars
            int j;
            for (j = 0; j < words[i].size() && j < words[i+1].size(); j++) {
                if (words[i][j] != words[i+1][j]) break;
            }
            // invalid, e.g. apple comes before app
            if (j == words[i+1].size() && words[i].size() > words[i+1].size()) {
                return "";
            }
            // if an edge doesnt exist, create an edge from the smaller to larger char
            if (j < words[i].size() && j < words[i+1].size() && !adj[words[i][j] - 'a'][words[i+1][j] - 'a']) {
                adj[words[i][j] - 'a'][words[i+1][j] - 'a'] = true;
                inDegree[words[i+1][j] - 'a']++;
            }
        }
        // push starting nodes
        int size = 0;
        for (int i = 0; i < 26; i++) {
            if (nodes[i] && inDegree[i] == 0) {
                q.push(i);
            }
            if (nodes[i]) size++;
        }
        // topological sort, with kahn's algorithm
        string result; 
        int count = 0;
        while (!q.empty()) {
            char u = q.front();
            q.pop();
            result.push_back(u + 'a');
            for (int v = 0; v < 26; v++) {
                if (adj[u][v]) {
                    inDegree[v]--;
                    if (inDegree[v] == 0) {
                        q.push(v);
                    }
                }
            }
            count++;
        }
        if (count < size) {
            return "";
        }
        return result;
    }
};
