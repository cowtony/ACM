class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int cur_max = 0;
        int count = 0;
        for (int i = 0; i < light.size(); i++) {
            cur_max = max(cur_max, light[i]);
            if (cur_max == i + 1) {
                count++;
            }
        }
        return count;
    }
};
