// lower_bound (WIP)
template<class Iterator>
    Iterator upper_bound(Iterator begin, Iterator end, typename Iterator::value_type target) {
        while (begin != end) {
            Iterator mid = std::next(begin, std::distance(begin, end) / 2);
        
            if (*mid < target) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        
        return end;
    }
