class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length = nums1.size() + nums2.size();
        int k = length / 2;

        if (length % 2 == 0) {
            return (findKthNumber(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), k) + 
                    findKthNumber(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), k + 1)) / 2.0;
        } else {
            return findKthNumber(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), k + 1);
        }
    }
    
    int findKthNumber(const vector<int>::iterator& a_begin, 
                      const vector<int>::iterator& a_end, 
                      const vector<int>::iterator& b_begin, 
                      const vector<int>::iterator& b_end, 
                      int k) {
        if (a_begin == a_end) {
            return *(b_begin + k - 1);
        }
        if (b_begin == b_end) {
            return *(a_begin + k - 1);
        }
        if (k == 1) {
            return min(*a_begin, * b_begin);
        }
        
        int a_val = (a_end - a_begin < k / 2) ? INT_MAX : *(a_begin + k / 2 - 1);
        int b_val = (b_end - b_begin < k / 2) ? INT_MAX : *(b_begin + k / 2 - 1);
        
        if (a_val < b_val) {
            return findKthNumber(a_begin + k / 2, a_end, b_begin, b_end, k - k / 2);
        } else {
            return findKthNumber(a_begin, a_end, b_begin + k / 2, b_end, k - k / 2);
        }
    }
};
