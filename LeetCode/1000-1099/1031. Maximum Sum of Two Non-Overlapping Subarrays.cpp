class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        vector<int> max_sum_1(nums.size(), 0);
        vector<int> max_sum_2(nums.size(), 0);
        int sum_1 = 0, sum_2 = 0;
        int result = INT_MIN;

        for (int i = 0; i < nums.size(); ++i) {
            sum_1 += nums[i];
            if (i >= firstLen) {
                sum_1 -= nums[i - firstLen];
            }
            max_sum_1[i] = i == 0? sum_1 : max(max_sum_1[i - 1], sum_1);
            
            sum_2 += nums[i];
            if (i >= secondLen) {
                sum_2 -= nums[i - secondLen];
            }
            max_sum_2[i] = i == 0? sum_2 : max(max_sum_2[i - 1], sum_2);

            if (i >= firstLen + secondLen - 1) {
                result = max({result, 
                              sum_1 + max_sum_2[i - firstLen], 
                              sum_2 + max_sum_1[i - secondLen]});
            }
        }

        return result;
    }
};
