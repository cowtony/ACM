template<class Iterator>
Iterator partition(Iterator begin, Iterator end) {
    static auto less = [](const typename Iterator::value_type& a, 
                          const typename Iterator::value_type& b){
        return a < b;
    };
    if (begin == end) { return begin; }
    --end;
    auto pivot = *begin;
    while (begin != end) {
        while (begin != end and !less(*end, pivot)) { --end; }
        *begin = *end;
        while (begin != end and less(*begin, pivot)) { ++begin; }
        *end = *begin;
    }
    *begin = pivot;
    return begin;
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Convert k to start from 0 and smallest.
        k = nums.size() - k;
        
        auto lo = nums.begin(), hi = nums.end();
        while (lo != hi) {
            auto mid = partition(lo, hi);
            if (mid - nums.begin() >= k) {
                hi = mid;
            } else if (mid - nums.begin() < k) {
                lo = mid + 1;
            }
        }
        return *lo;
    }
};
