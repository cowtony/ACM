class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // Partition sort by median.
        auto midptr = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int median = *midptr;
        
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
};
