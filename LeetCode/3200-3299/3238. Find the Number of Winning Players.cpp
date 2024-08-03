class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> count(n, vector<int>(11, 0));
        for (const auto& p : pick) {
            count[p[0]][p[1]]++;
        }
        
        int winner = 0;
        for (int i = 0; i < n; i++) {
            for (int num : count[i]) {
                if (num > i) {
                    winner++;
                    break;
                }
            }
        }
        return winner;
    }
};
