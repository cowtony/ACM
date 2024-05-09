class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long result = 0;
        for (int i = 0; i < k; i++) {
            result += max(0, happiness[i] - i);
        }
        return result;
    }
};
