class Solution {
public:
    /**
     * @param D: The sorted set of digits.
     * @param N: 
     * @return: The number of positive integers that can be written.
     */
    int atMostNGivenDigitSet(vector<string> &D, int N) {
        vector<int> digits;
        vector<int> full_count;
        full_count.push_back(1);
        while (N > 0) {
            digits.push_back(N % 10);
            N /= 10;
            full_count.push_back(full_count.back() * D.size());
        }
        
        set<int> DD;
        vector<int> digit_lower(10, 0);
        for (string d : D) {
            int digit = stoi(d);
            DD.insert(digit);
            for (int i = digit + 1; i < digit_lower.size() ; i++) {
                digit_lower[i]++;
            }
        }
        
        int sum = 0;
        // Prepare all answers shorter than N.
        for (int j = digits.size() - 1; j > 0; j--) {
            sum += full_count[j];
        }
        // When N[i] in D:
        for (int i = digits.size() - 1; i >= 0; i--) {
            sum += full_count[i] * digit_lower.at(digits[i]);
            if (DD.find(digits[i]) == DD.end()) {
                return sum;
            }
        }
        
        return sum + 1;
    }
};
