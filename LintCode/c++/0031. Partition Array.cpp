class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int pivot) {
        int lo = 0, hi = nums.size() - 1;
        while(lo <= hi) {
            while(lo <= hi && nums[hi] >= pivot) { --hi; }
            while(lo <= hi && nums[lo] < pivot) { ++lo; }
            if (lo < hi) { swap(nums[lo++], nums[hi--]); }
        }
        return lo;
    }
};
