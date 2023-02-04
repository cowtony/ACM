class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        
        int target = 1;
        for (int coin : coins) {
            if (coin <= target) {
                target += coin;
            } else {
                break;
            }
        }
        return target;
    }
};