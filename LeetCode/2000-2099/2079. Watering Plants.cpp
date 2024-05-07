class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int water = capacity;
        int steps = 0;
        for (int i = 0; i < plants.size(); i++) {
            if (water < plants[i]) {
                steps += i * 2;
                water = capacity;
            }
            steps++;
            water -= plants[i];
        }
        return steps;
    }
};
