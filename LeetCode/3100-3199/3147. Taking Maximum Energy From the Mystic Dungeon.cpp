class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int result = INT_MIN;
        for (int start = energy.size() - 1, t = 0; t < k; t++, start--) {
            int e = 0;
            for (int i = start; i >= 0; i-= k) {
                e += energy[i];
                result = max(result, e);
            }
        }
        return result;
    }
};
