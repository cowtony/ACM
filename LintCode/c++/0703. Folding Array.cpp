class Solution {
public:
    /**
     * @param nums: the original array
     * @param req: the direction each time
     * @return: the final folded array 
     */
    vector<int> folding(vector<int> &nums, vector<int> &req) {
        for (int fold = 0, base = nums.size() >> 1; fold < req.size(); fold++, base >>= 1) {
            int lo = 0, hi = nums.size() - base;
            bool turn = true;
            while (lo < hi) {
                reverse(nums.begin() + lo, nums.begin() + hi);
                
                if (turn) {
                    lo += base;
                } else {
                    hi -= base;
                }
                turn = !turn;
            }
            
            cout << endl;
            
            // The only difference of left fold and right fold is reverse or not at the end.
            if (req.at(fold) == 1) {
                reverse(nums.begin(), nums.end());
            }
        }
        return nums;
    }
};
