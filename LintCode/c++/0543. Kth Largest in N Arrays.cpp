class Solution {
public:
    /**
     * @param arrays: a list of array
     * @param k: An integer
     * @return: an integer, K-th largest element in N arrays
     */
    int KthInArrays(vector<vector<int>> &arrays, int k) {
        // Put N arrays into one.
        vector<int> nums;
        for (const vector<int>& array : arrays) {
            nums.insert(nums.end(), array.begin(), array.end());
        }
        
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int pos = partition(nums, start, end);

            if (k < pos + 1) {
                end = pos - 1;
            } else if (k > pos + 1) {
                start = pos + 1;
            } else {
                return nums[k - 1];
            }
        }
        return nums[k - 1];
    }
    
    int partition(vector<int>& nums, int start, int end) {
        const int pivot = nums[start];
        
        while (start < end) {
            while (start < end and nums[end] <= pivot) {
                end--;
            }
            nums[start] = nums[end];
            while (start < end and nums[start] >= pivot) {
                start++;
            }
            nums[end] = nums[start];
        }
        nums[start] = pivot;
        return start;
    }
};
