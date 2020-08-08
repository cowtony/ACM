class Solution {
public:
    int longestAwesome(string s) {
        vector<int> earliest(1 << 10, 1E6), latest(1 << 10, -1);
        earliest[0] = 0;
        latest[0] = 0;
        int odd = 0b0000000000; // Bit represent odd count for that digit.
        
        for (int i = 0; i < s.length(); i++) {
            odd ^= 1UL << (s[i] - '0');
            // cout << bitset<10>(odd) << endl;
            earliest[odd] = min(earliest[odd], i + 1);
            latest[odd] = i + 1;
        }
        
        int res = 1;
        for (int i = 0; i < 1024; i++) {
            if (latest[i] >= 0) {
                res = max(res, latest[i] - earliest[i]);
                for (int j = 1; j < 1024; j <<= 1) {
                    res = max(res, latest[i] - earliest[i ^ j]);
                }
            }
        }
        return res;
    }
};
