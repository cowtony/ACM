class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        sort(cards.rbegin(), cards.rend());

        int last_odd = 0;
        int last_even = 0;
        int sum = 0;
        for (int i = 0; i < cnt; i++) {
            if (cards[i] % 2 == 1) {
                last_odd = cards[i];
            } else {
                last_even = cards[i];
            }
            sum += cards[i];
        }

        if (sum % 2 == 0) {
            return sum;
        }

        int next_odd = 0;
        int next_even = 0;
        for (int i = cnt; i < cards.size(); i++) {
            if (next_odd == 0 && cards[i] % 2 == 1) {
                next_odd = cards[i];
            }
            if (next_even == 0 && cards[i] % 2 == 0) {
                next_even = cards[i];
            }
            if (next_odd != 0 && next_even != 0) {
                break;
            }
        }

        int result = 0;
        if (last_odd != 0 && next_even != 0) {
            result = max(result, sum - last_odd + next_even);
        }
        if (last_even != 0 && next_odd != 0) {
            result = max(result, sum - last_even + next_odd);
        }
        return result;
    }
};
