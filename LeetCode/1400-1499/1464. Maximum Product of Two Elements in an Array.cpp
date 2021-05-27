class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = 0;
        int second = 0;
        
        for (int num : nums) {
            if (num >= first) {
                second = first;
                first = num;
            } else if (num > second) {
                // Consider the corner case when the first element is the largest.
                second = num;
            }
        }

        return (first - 1) * (second - 1);
    }
};
