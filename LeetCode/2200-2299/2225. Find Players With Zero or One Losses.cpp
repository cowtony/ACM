class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> loss_count;
        for (const auto& match : matches) {
            loss_count[match[0]];
            loss_count[match[1]]++;
        }

        vector<vector<int>> result(2);
        for (const auto& [team, count] : loss_count) {
            if (count == 0) {
                result[0].push_back(team);
            } else if (count == 1) {
                result[1].push_back(team);
            }
        }
        sort(result[0].begin(), result[0].end());
        sort(result[1].begin(), result[1].end());
        return result;
    }
};
