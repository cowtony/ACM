class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> count(1024, 0);
        int mask = 0;
        count[mask] = 1;

        long long result = 0;
        for (auto c : word) {
            mask ^= 1 << (c - 'a');
            result += count[mask];  // even count scenario.
            for (int i = 0, n = 1; i < 10; i++, n <<= 1) {
                result += count[mask ^ n];  // 1 odd count scenario.
            }
                
            count[mask]++;
        }
        return result;
    }
};
