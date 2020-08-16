class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        if (digits.empty()) {
            return "";
        }
        int digit_sum = 0;
        vector<int> count(10, 0);
        for (int digit : digits) {
            count[digit]++;
            digit_sum += digit;
        }
        
        while (digit_sum % 3 != 0) {
            if (digit_sum % 3 == 1) {
                for (int d : {1, 4, 7, 2, 5, 8}) {
                    if (count[d] > 0) {
                        count[d]--;
                        digit_sum -= d;
                        break;
                    }
                }
            } else { // digit_sum % 3 == 2
                for (int d : {2, 5, 8, 1, 4, 7}) {
                    if (count[d] > 0) {
                        count[d]--;
                        digit_sum -= d;
                        break;
                    }
                }
            }
        }
        
        string res;
        for (int digit = 9; digit >= 0; digit--) {
            res += string(count[digit], '0' + digit);
        }
        return res[0] == '0'? "0" : res;
    }
};
