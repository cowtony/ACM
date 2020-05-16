class Solution {
public:
    /**
     * @param target: The target distance
     * @param original: The original gas
     * @param distance: The distance array
     * @param apply: The apply array
     * @return: Return the minimum times
     */
    int getTimes(int target, int original, vector<int> &distance, vector<int> &apply) {
        priority_queue<int> gas;
        int count = 0;
        for (int i = 0; i < distance.size(); i++) {
            while (original < distance[i]) {
                if (gas.empty()) {
                    return -1;
                }
                original += gas.top();
                gas.pop();
                count++;
                if (original >= target) {
                    return count;
                }
            }
            gas.push(apply[i]);
        }
        return count;
    }
};
