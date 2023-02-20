class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<int, int> count;
        for (int rank : ranks) {
            count[rank]++;
        }
        if (isFlush(suits)) {
            return "Flush";
        }
        if (hasSameRank(count, 3)) {
            return "Three of a Kind";
        }
        if (hasSameRank(count, 2)) {
            return "Pair";
        }
        return "High Card";
    }

    bool isFlush(const vector<char>& suits) {
        for (int i = 1; i < suits.size(); i++) {
            if (suits[i] != suits[i - 1]) {
                return false;
            }
        }
        return true;
    }

    bool hasSameRank(const unordered_map<int, int>& count, int target) {
        for (const auto& [rank, c] : count) {
            if (c >= target) {
                return true;
            }
        }
        return false;
    }
};
