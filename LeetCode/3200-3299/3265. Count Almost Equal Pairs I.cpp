class Solution {
public:
    int countPairs(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (almostEqual(nums[i], nums[j])) {
                    count++;
                }
            }
        }
        return count;
    }

    bool almostEqual(int a, int b) {
        int diff_count = 0;
        int diff_a = -1, diff_b = -1;
        while (a || b) {
            int digit_a = 0, digit_b = 0;

            if (a != 0) {
                digit_a = a % 10;
            }
            if (b != 0) {
                digit_b = b % 10;
            }
            if (digit_a != digit_b) {
                diff_count++;

                if (diff_count == 1) {  // first time
                    diff_a = a % 10;
                    diff_b = b % 10;
                } else if (diff_count == 2) {
                    if ((diff_a !=( b % 10)) || (diff_b != (a % 10))) {
                        return false;
                    }
                } else { // > 2
                    return false;
                }
            }
            a /= 10;
            b /= 10;
        }

        return diff_count == 2 || diff_count == 0;
    }
};
