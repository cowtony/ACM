class Solution {
public:
    int numTeams(vector<int>& rating) {
        int count = 0;
        vector<int> less(rating.size(), 0);
        vector<int> more(rating.size(), 0);
        for (int i = 1; i < rating.size() - 1; i++) {
            int less_left = 0;
            int more_left = 0;
            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i]) {
                    less_left++;
                } else {
                    more_left++;
                }
            }
            int less_right = 0;
            int more_right = 0;
            for (int j = i + 1; j < rating.size(); j++) {
                if (rating[j] < rating[i]) {
                    less_right++;
                } else {
                    more_right++;
                }
            }
            count += less_left * more_right + more_left * less_right;
        }
        return count;
    }
};
