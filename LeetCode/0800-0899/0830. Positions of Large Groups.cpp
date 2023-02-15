class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        s += '*';
        vector<vector<int>> result;
        int consecutive = 1, prev = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                consecutive++;
            } else {
                if (consecutive >= 3) {
                    result.push_back({prev, i - 1});
                }
                prev = i;
                consecutive = 1;
            }
        }
        return result;
    }
};
