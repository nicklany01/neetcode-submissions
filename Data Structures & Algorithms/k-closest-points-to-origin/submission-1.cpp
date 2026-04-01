class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, vector<int>>> pq;
        for (auto point : points) {
            float d = sqrt((pow(point[0], 2) + pow(point[1], 2)));
            pq.push({d, point});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> result;
        int size = pq.size();
        for (int i = 0; i < size; i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
