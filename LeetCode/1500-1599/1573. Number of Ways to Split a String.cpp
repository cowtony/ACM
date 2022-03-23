class Solution {
public:
    int numWays(string s) {
        vector<int64_t> pos;
        for (int i = 0; i < s.length(); ++i) {
            if (s.at(i) == '1') {
                pos.push_back(i);
            }
        }
        
        if (pos.size() % 3 != 0) {
            return 0;
        } else if (pos.empty()) {
            return Combination(s.length() - 1, 2) % kMod;
        } else {
            int num = pos.size() / 3;
            return (pos[num] - pos[num - 1]) * (pos[2 * num] - pos[2 * num - 1]) % kMod;
        }
    }

private:
    
    int64_t Combination(int a, int b) {
        int64_t result = 1;
        for (int i = a, j = 1; j <= b; --i, ++j) {
            result *= i;
            result /= j;
        }
        return result;
    }
    
    const int kMod = 1000000007;
};
