class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        
        const int kNumsOnLeft = (nums1.size() + nums2.size()) / 2;  // Numbers to ignore (for the ODD length case).
        int count_1, count_2;  // The `numbers to ignore` for the 2 vectors. The total should be equal to k.
        int min_count_1 = 0, max_count_1 = nums1.size();
        while (min_count_1 <= max_count_1) {
            count_1 = (min_count_1 + max_count_1) / 2;
            count_2 = kNumsOnLeft - count_1;
            
            if (count_2 < 0) {
                max_count_1 = count_1 - 1;
                continue;
            } else if (count_2 > nums2.size()) {
                min_count_1 = count_1 + 1;
                continue;
            }
            
            if (count_2 > 0 and count_1 < nums1.size() and nums1[count_1] < nums2[count_2 - 1]) {
                min_count_1 = count_1 + 1;
            } else if (count_1 > 0 and nums2[count_2] < nums1[count_1 - 1]) {
                max_count_1 = count_1 - 1;
            } else {
                break;
            }
        }    
        
        int left_val = max(count_1 > 0? nums1[count_1 - 1] : INT_MIN, 
                           count_2 > 0? nums2[count_2 - 1] : INT_MIN);
        int right_val = min(count_1 < nums1.size()? nums1[count_1] : INT_MAX, 
                            count_2 < nums2.size()? nums2[count_2] : INT_MAX);

        if ((nums1.size() + nums2.size()) % 2 == 0) {
            return (left_val + right_val) / 2.0;
        } else {
            return right_val;
        }
    }
};
