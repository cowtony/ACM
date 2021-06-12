class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int reach = startFuel;
        priority_queue<int> gas;
        for (int pump = 0, i = 0; ; pump++) {
            if (reach >= target) {
                return pump;
            }
            while (i < stations.size() && stations[i][0] <= reach) {
                gas.push(stations[i][1]);
                i++;
            }
            if (gas.empty()) {
                return -1;
            }
            reach += gas.top();
            gas.pop();
        }
    }
};
