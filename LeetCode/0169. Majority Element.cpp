class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority;
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                majority = num;
            }
            if (num == majority) {
                count++;
            } else {
                count--;
            }
        }
        return majority;
    }
};
