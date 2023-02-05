// lower_bound (WIP)
template<class Iterator>
Iterator UpperBound(Iterator begin, Iterator end, typename Iterator::value_type target) {
    while (begin != end) {
        Iterator mid = std::next(begin, std::distance(begin, end) / 2);
        if (*mid <= target) {
            begin = mid + 1;
        } else {  // *mid > target
            end = mid;
        }
    }
    return begin;
}

// Bias to low.
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (??) {
        lo = mid + 1;
    } else {
        hi = mid;
    }
}
return lo;

// Bias to high.
while (lo < hi) {
    int mid = lo + (hi - lo + 1) / 2;
    if (??) {
        lo = mid;
    } else {
        hi = mid - 1;
    }
}
return lo;

/*
 * Binary search the answer:
 * LeetCode 2560: https://leetcode.com/problems/house-robber-iv/description/
 */
