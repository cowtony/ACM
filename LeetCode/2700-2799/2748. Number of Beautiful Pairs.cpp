class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        vector<int> count(10, 0);
        int result = 0;
        for (int num : nums) {
            for (int i = 1; i < 10; i++) {
                if (gcd(i, num % 10) == 1) {
                    result += count[i];
                }
            }

            int first_digit;
            while (num) {
                first_digit = num;
                num /= 10;
            }
            count[first_digit]++;
        }
        return result;
    }

    int gcd(int a, int b) {
        if (a == 0) { return b; }
        return gcd(b % a, a);
    }
};
