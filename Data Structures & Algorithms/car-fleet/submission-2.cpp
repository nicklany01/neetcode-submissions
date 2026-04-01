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
        for (auto p : cars) {
            cout << p.first << p.second << "\n";
        }
        for (int i = cars.size() - 1; i >= 0; i--) {
            float time = static_cast<float>(target - cars[i].first) / cars[i].second; 
            cout << "time: " << time << "\n" << "x: " << target - cars[i].first << ", s: " << cars[i].second << "\n";
            if (time > maxTime) {
                maxTime = time;
                cout << "maxTime: " << maxTime << "\n";
                result++;
            }
        }
        return result;
    }
};
