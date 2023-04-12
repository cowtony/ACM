class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> count;
        int result = -1, max_count = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                count[num]++;
                if (count[num] > max_count || count[num] == max_count && result > num) {
                    max_count = count[num];
                    result = num;
                }
            }
        }
        return result;
    }
};
