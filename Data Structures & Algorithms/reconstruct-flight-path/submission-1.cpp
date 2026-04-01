class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // create adjacency list
        unordered_map<string,vector<string>> adj;
        for (auto& t : tickets) {
            adj[t[0]].push_back(t[1]);
        }
        // sort in reverse lexigraphical order so we can use pop_back for O(1)
        for (auto& [src, dests] : adj) {
            sort(dests.rbegin(), dests.rend());
        }
        vector<string> result;
        stack<string> st;
        st.push("JFK");
        while (!st.empty()) {
            // remove all neighbours and add it to stack for post order traversal
            // if there are none left dfs on that node is done, and add it to result
            string curr = st.top();
            if (adj[curr].empty()) {
                result.push_back(curr);
                st.pop();
            } else {
                st.push(adj[curr].back());
                adj[curr].pop_back();
            }
        }
        // captured in post order, so need to reverse it
        reverse(result.begin(), result.end());
        return result;
    }
};
