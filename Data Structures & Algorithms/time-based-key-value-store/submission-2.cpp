class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> m; 
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        // insert to map, input will be in increasing order
        m[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        auto it = m.find(key);
        if (it != m.end()) {
            auto& v = it->second;
            int r = v.size() - 1;
            int l = 0;
            int m = r / 2;
            string bestMatch = "";
            while (l <= r) {
                if (v[m].second == timestamp) {
                    return v[m].first;
                } else if (v[m].second < timestamp) {
                    bestMatch = v[m].first;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
                m = (r + l) / 2;
            }
            return bestMatch;
        } else {
            return "";
        }
    }
};
