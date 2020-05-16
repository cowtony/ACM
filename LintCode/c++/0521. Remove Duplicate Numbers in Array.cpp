class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int> &nums) {
        set<int> numbers;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            nums[j] = nums[i];
            if (numbers.find(nums[j]) == numbers.end()) {
                numbers.insert(nums[j]);
                j++;
            }
        }
        return numbers.size();
    }
};
