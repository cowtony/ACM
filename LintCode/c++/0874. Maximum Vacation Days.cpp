class Solution {
public:
    /**
     * @param flights: the airline status from the city i to the city j
     * @param days: days[i][j] represents the maximum days you could take vacation in the city i in the week j
     * @return: the maximum vacation days you could take during K weeks
     */
    int maxVacationDays(vector<vector<int>> &flights, vector<vector<int>> &days) {
        vector<vector<int>> dp(days[0].size(), vector<int>(days.size(), -1));

        for (int city = 0; city < flights.size(); city++) {
            if (flights[0][city] or city == 0) {
                dp[0][city] = days[city][0];
            }
        }
        
        for (int week = 1; week < dp.size(); week++) {
            for (int next_city = 0; next_city < dp[0].size(); next_city++) {
                for (int previous_city = 0; previous_city < dp[0].size(); previous_city++) {
                    if (dp[week - 1][previous_city] == -1) {
                        continue;
                    }
                    if (flights[previous_city][next_city] or previous_city == next_city) {
                        dp[week][next_city] = max(dp[week][next_city], dp[week - 1][previous_city] + days[next_city][week]);
                    }
                }
            }
        }
        
        int max_vacation = 0;
        for (int city = 0; city < dp[0].size(); city++) {
            max_vacation = max(max_vacation, dp.back().at(city));
        }
        
        return max_vacation;
    }
};
