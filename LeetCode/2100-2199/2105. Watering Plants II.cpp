class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int count = 0;
        // Alice
        int waterA = capacityA;
        for (int i = 0; i < plants.size() / 2; i++) {
            if (waterA < plants[i]) {
                count++;
                waterA = capacityA;
            }
            waterA -= plants[i];
        }
        // Bob
        int waterB = capacityB;
        for (int i = plants.size() - 1; i > (plants.size() - 1) / 2; i--) {
            if (waterB < plants[i]) {
                count++;
                waterB = capacityB;
            }
            waterB -= plants[i];
        }

        // Meet in middle
        if (plants.size() % 2 == 1) {
            int plant = plants[plants.size() / 2];
            if (waterA >= waterB) {  // Alice
                if (waterA < plant) {
                    count++;
                }
            } else {  // Bob
                if (waterB < plant) {
                    count++;
                }
            }
        }
        return count;
    }
};
