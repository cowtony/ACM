class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        bool flip = true;
        for (int i = 1; i < nums.size(); i++) {
            if (flip) {
                if (nums[i] < nums[i - 1]) {
                    swap(nums[i], nums[i - 1]);
                }
            } else {
                if (nums[i] > nums[i - 1]) {
                    swap(nums[i], nums[i - 1]);
                }
            }
            flip = !flip;
        }
    }
};
