class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        auto less = [](const auto& a, const auto& b){return a < b;};
        mergeSort(nums.begin(), nums.end(), less);
        // quickSort(nums.begin(), nums.end(), less);
        return nums;
    }
    
    template<class Iterator, class Compare>
    int inplace_merge(const Iterator& begin, const Iterator& mid, const Iterator& end, const Compare& compare) {
        std::vector<typename Iterator::value_type> temp;
        temp.reserve(std::distance(begin, end));
        Iterator l = begin, r = mid;
        int count = 0;
        for (Iterator l = begin; l != mid; l++) {
            while (r != end and compare(*r, *l)) { temp.emplace_back(*r++); }
            temp.emplace_back(*l); 
        }
        temp.insert(temp.end(), r, end);
        std::move(temp.begin(), temp.end(), begin);
        return count;
    }
    template<class Iterator, class Compare>
    int mergeSort(const Iterator& begin, const Iterator& end, const Compare& compare) {
        int size = std::distance(begin, end);   
        if (size <= 1) { return 0; }
        Iterator mid = std::next(begin, size / 2);
        return mergeSort(begin, mid, compare) // sort left half
             + mergeSort(mid, end, compare) // sort right half
             + inplace_merge(begin, mid, end, compare); // merge left and right. `std::implace_merge()`
    }

    template<class Iterator, class Compare>
    Iterator partition(Iterator begin, Iterator end, const Compare& compare) {
        if (begin == end--) { return begin; }
        auto pivot = *begin;
        while (begin != end) {
            while (begin != end and !compare(*end, pivot)) { --end; }
            *begin = *end;
            while (begin != end and compare(*begin, pivot)) { ++begin; }
            *end = *begin;
        }
        *begin = pivot;
        return begin;
    }
    template<class Iterator, class Compare>
    void quickSort(Iterator begin, Iterator end, const Compare& compare) {
        while (begin != end) {
            auto mid = partition(begin, end, compare);
            if (mid - begin < end - mid) {
                quickSort(begin, mid, compare);
                begin = mid + 1;
            } else {
                quickSort(mid + 1, end, compare);
                end = mid;
            }
        }
    }
};
