class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int s1 = getScore(player1);
        int s2 = getScore(player2);
        if (s1 > s2) {
            return 1;
        } else if (s1 < s2) {
            return 2;
        } else {
            return 0;
        }
    }
    
    int getScore(vector<int>& nums) {
        int score = 0, last_10 = 0;
        for (int num : nums) {
            score += num * (last_10-- > 0? 2 : 1);
            if (num == 10) {
                last_10 = 2;
            }
        }
        return score;
    }
};
