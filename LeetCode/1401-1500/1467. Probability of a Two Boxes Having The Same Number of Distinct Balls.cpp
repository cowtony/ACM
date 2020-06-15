class Solution {
public:
    double getProbability(vector<int>& balls) {
        int sum = 0;
        for (int ball : balls) {
            sum += ball;
        }
        
        // This array store the picked balls in one box.
        // `balls - picks` will then in another box.
        vector<int> picks(balls.size(), 0); 
        return double(DFS(balls, picks, sum / 2, 0)) / combinition(sum, sum / 2);
    }
    
    long DFS(const vector<int>& balls, vector<int>& picks, int remain, int idx) {
        if (remain == 0) {
            if (sameDistinctBall(balls, picks)) {
                long res = 1;
                for (int i = 0; i < balls.size(); i++) {
                    res *= combinition(balls.at(i), balls.at(i) - picks.at(i));
                }
                return res;
            }
            return 0;
        }
        if (idx >= balls.size()) {
            return 0;
        }
        long res = 0;
        // Search all possible picks for next index position.
        for (int i = 0; i <= balls.at(idx) and i <= remain; ++i) {
            picks[idx] = i;
            res += DFS(balls, picks, remain - i, idx + 1);
        }
        picks[idx] = 0;
        return res;
    }
    
    long combinition(int from, int pick) {
        pick = min(pick, from - pick);
        long res = 1;
        for (int i = 1, j = from; i <= pick; i++, j--) {
            res *= j;
            res /= i;
        }
        return res;
    }
    
    bool sameDistinctBall(const vector<int>& balls, const vector<int>& pick) {
        int box_a = 0, box_b = 0;
        for (int i = 0; i < balls.size(); ++i) {
            if (pick.at(i) > 0) {
                ++box_a;
            }
            if (balls.at(i) - pick.at(i) > 0) {
                ++box_b;
            }
        }
        return box_a == box_b;
    }
};
