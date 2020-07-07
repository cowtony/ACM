class Solution {
public:
    int rob(vector<int>& nums) {
        int robbed = 0;
        int skipped = 0;

        for (int num : nums) {
            int previous_robbed = robbed;
            robbed = skipped + num;
            skipped = max(skipped, previous_robbed);
        }
        return max(robbed, skipped);
    }
};
