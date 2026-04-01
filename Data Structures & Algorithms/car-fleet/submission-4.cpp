class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        int result = 0;
        float maxTime = 0;
        sort(cars.begin(), cars.end());
        for (int i = cars.size() - 1; i >= 0; i--) {
            float time = static_cast<float>(target - cars[i].first) / cars[i].second; 
            if (time > maxTime) {
                maxTime = time;
                result++;
            }
        }
        return result;
    }
};
