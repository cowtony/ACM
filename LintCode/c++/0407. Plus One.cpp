class Solution {
public:
    /**
     * @param digits: a number represented as an array of digits
     * @return: the result
     */
    vector<int> plusOne(vector<int> &digits) {
        digits[digits.size() - 1]++;
        digits.insert(digits.begin(), 0);
        for (int i = digits.size() - 1; i >= 1; i--)
        {
            if (digits[i] >= 10)
            {
                digits[i] -= 10;
                digits[i - 1]++;
            }
            else break;
        }
        
        if (digits[0] == 0)
            digits.erase(digits.begin());
        return digits;
    }
};
