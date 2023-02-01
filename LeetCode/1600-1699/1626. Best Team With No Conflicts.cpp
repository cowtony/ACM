class Solution {
public:
    struct Player {
        Player(int a, int s) : age(a), score(s) {}

        int age;
        int score;
    };

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<Player> players;
        for (int i = 0; i < scores.size(); i++) {
            players.emplace_back(ages[i], scores[i]);
        }

        sort(players.begin(), players.end(), [](const Player& a, const Player& b){
            if (a.age == b.age) {
                return a.score < b.score;
            }
            return a.age < b.age;
        });

        vector<int> dp(players.size(), 0);
        for (int i = 0; i < players.size(); i++) {
            dp[i] = players[i].score;
            for (int j = 0; j < i; j++) {
                // avoid conflicts
                if (!(players[i].age > players[j].age and players[i].score < players[j].score)) {
                    // transfer function
                    dp[i] = max(dp[i], dp[j] + players[i].score);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};