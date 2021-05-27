class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto lo = points.begin(), hi = points.end();
        while (lo != hi) {
            auto mid = partition(lo, hi);
            if (mid - points.begin() < K) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
    
    template<class Iterator>
    Iterator partition(Iterator begin, Iterator end) {
        static auto less = [](const typename Iterator::value_type& a, const typename Iterator::value_type& b){
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        };
        
        if (begin == end) {
            return begin;
        }
        --end;
        
        auto pivot = *begin;
        while (begin != end) {
            while (begin != end and !less(*end, pivot)) {
                --end;
            }
            *begin = *end;
            while (begin != end and less(*begin, pivot)) {
                ++begin;
            }
            *end = *begin;
        }
        *begin = pivot;
        return begin;
    }
};
