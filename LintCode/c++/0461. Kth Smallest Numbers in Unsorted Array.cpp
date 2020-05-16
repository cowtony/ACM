class Solution {
public:
    /**
     * @param k: An integer
     * @param nums: An integer array
     * @return: kth smallest element
     */
    int kthSmallest(int k, vector<int> &nums) {
        return findKthLargest(nums, nums.size() - k + 1);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        // Convert k to start from 0 and smallest.
        k = nums.size() - k;
        
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int curr = partition(nums, lo, hi);
            if (curr > k) {
                hi = curr - 1;
            } else if (curr < k) {
                lo = curr + 1;
            } else {
                return nums[curr];
            }
        }
        return nums[lo];
    }
    
    int partition(vector<int>& arr, int begin_idx, int end_idx)
    {
        int pivot = arr[begin_idx];
        while(begin_idx < end_idx)
        {
            while(begin_idx < end_idx && arr[end_idx] >= pivot) {
                --end_idx;
            }
            arr[begin_idx] = arr[end_idx];
            
            while(begin_idx < end_idx && arr[begin_idx] <= pivot) {
                ++begin_idx;
            }
            arr[end_idx] = arr[begin_idx];
        }
        arr[begin_idx] = pivot;
        return begin_idx;
    }
};
