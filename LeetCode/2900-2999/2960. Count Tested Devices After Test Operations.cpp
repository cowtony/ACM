class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int tested = 0;
        for (int battery : batteryPercentages) {
            if (battery > tested) {
                tested++;
            }
        }
        return tested;
    }
};
