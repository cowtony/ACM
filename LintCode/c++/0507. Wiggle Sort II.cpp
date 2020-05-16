class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        // Partition sort by median.
        // auto midptr = nums.begin() + nums.size() / 2;
        // nth_element(nums.begin(), midptr, nums.end());
        // int median = *midptr;
        int median = findKthElement(nums, nums.size() / 2);
        
        // Index-rewiring.
        #define A(i) nums[(1 + 2 * (i)) % (nums.size() | 1)]
        
        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int lo = 0, mid = 0, hi = nums.size() - 1;
        while (mid <= hi) {
            if (A(mid) > median) {
                swap(A(lo), A(mid));
                lo++;
                mid++;
            }
            else if (A(mid) < median) {
                swap(A(mid), A(hi));
                hi--;
            }
            else {
                mid++;
            }
        }
    }
    
    int findKthElement(vector<int>& nums, int k) {        
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
