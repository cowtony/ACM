class Solution {
public:
    /**
     * @param nums: a binary array
     * @return:  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int count = 0;
        int max_count= 0;
        for (int num : nums) {
            if (num == 1) {
                count++;
                max_count = max(max_count, count);
            } else {
                count = 0;
            }
        }
        return max_count;
    }
};
