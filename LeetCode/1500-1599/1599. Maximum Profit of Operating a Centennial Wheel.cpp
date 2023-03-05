class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int max_profit = 0;
        int best_round = -1;
        int round = 0;
        int profit = 0;
        int queued = 0;
        for (int i = 0; i < customers.size(); i++) {
            queued += customers[i];

            if (queued >= 4) {
                profit += queued / 4 * (4 * boardingCost - runningCost);
                round += queued / 4;
                queued -= queued / 4 * 4;
            } else if (round == i) {
                profit += queued * boardingCost - runningCost;
                round++;
                queued = 0;
            }

            if (profit > max_profit) {
                max_profit = profit;
                best_round = round;
            }
        }

        if (queued > 0) {
            profit += queued * boardingCost - runningCost;
            queued = 0;
            round++;
        }
        if (profit > max_profit) {
            max_profit = profit;
            best_round = round;
        }

        return best_round;
    }
};
