class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int total = mean * (rolls.size() + n);
        total -= accumulate(rolls.begin(), rolls.end(), 0);

        if (total < n || total > 6 * n) {
            return {};
        }

        vector<int> result(n, total / n);
        for (int i = 0; i < total % n; i++) {
            result[i]++;
        }
        return result;
    }
};
