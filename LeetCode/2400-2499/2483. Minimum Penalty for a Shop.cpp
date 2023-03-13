class Solution {
public:
    int bestClosingTime(string customers) {
        const int kTotalY = 0;  // For better understanding
        int min_penalty = kTotalY, result = 0;
        int penalty = kTotalY;
        for (int i = 0; i < customers.length(); ++i) {
            if (customers[i] == 'N') {
                penalty++;
            } else { // == 'Y'
                penalty--;  // kTotalY (unknown const) - SeenY
            }
            if (penalty < min_penalty) {
                min_penalty = penalty;
                result = i + 1;
            }
        }
        return result;
    }
};
