class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<bool> visited(1 << k, false);
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            num = (num << 1) + (s[i] - '0');
            num &= (1 << k) - 1;

            if (i >= k - 1) {
                visited[num] = true;
            }
        }
        for (int v : visited) {
            if (v == false) {
                return false;
            }
        }
        return true;
    }
};
