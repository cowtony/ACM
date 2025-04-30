class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            if (digitCount(num) % 2 == 0) {
                count++;
            }
        }
        return count;
    }

    int digitCount(int num) {
        if (num == 0) {
            return 1;
        }
        int result = 0;
        while (num) {
            num /= 10;
            result++;
        }
        return result;
    }
};
