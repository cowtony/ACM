class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int check = 1;
        for (int num : nums) {
            if (num > check) {
                break;
            } else if (num == check) {
                check <<= 1;
            }
        }
        return check;
    }
};
