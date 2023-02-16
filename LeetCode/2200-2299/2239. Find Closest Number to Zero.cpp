class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int result = INT_MAX;
        for (int num : nums) {
            if (abs(num) == abs(result) && num > result || abs(num) < abs(result)) {
                result = num;
            }
        }
        return result;
    }
};
