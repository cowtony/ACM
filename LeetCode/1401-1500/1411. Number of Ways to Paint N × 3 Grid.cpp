class Solution {
public:
    int numOfWays(int n) {
        int64_t aba = 6;
        int64_t abc = 6;
        for (int i = 1; i < n; i++) {
            int64_t next_aba = (abc * 2 + aba * 3) % 1000000007;
            int64_t next_abc = (abc * 2 + aba * 2) % 1000000007;
            aba = next_aba;
            abc = next_abc;
        }
        return (aba + abc) % 1000000007;
    }
};
