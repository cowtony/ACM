class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cur_max = 1;
        int cur_min = 1;
        int all_max = INT_MIN;
        for (int num : nums) {
            if (num < 0) {
                swap(cur_max, cur_min);
            }
            cur_max = max(num, cur_max * num);
            cur_min = min(num, cur_min * num);

            all_max = max(all_max, cur_max);
        }
        return all_max;
    }
};
