class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sorted_score = score;
        sort(sorted_score.rbegin(), sorted_score.rend());
        unordered_map<int, int> rank;
        for (int i = 0; i < sorted_score.size(); i++) {
            rank[sorted_score[i]] = i + 1;
        }

        vector<string> result;
        for (int s : score) {
            int r = rank[s];
            if (r == 1) {
                result.push_back("Gold Medal");
            } else if (r == 2) {
                result.push_back("Silver Medal");
            } else if (r == 3) {
                result.push_back("Bronze Medal");
            } else {
                result.push_back(to_string(r));
            }
        }
        return result;
    }
};
