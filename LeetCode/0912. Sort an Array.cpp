namespace mniu {
template<class Iterator, class Compare>
void inplace_merge(const Iterator& begin, const Iterator& mid, const Iterator& end, const Compare& compare) {
    std::vector<typename Iterator::value_type> temp;
    temp.reserve(std::distance(begin, end));
    Iterator l = begin;
    Iterator r = mid;
    while (l != mid and r != end) {
        if (compare(*r, *l)) { temp.emplace_back(*r++); }
        else { temp.emplace_back(*l++); }
    }
    temp.insert(temp.end(), l, mid);
    temp.insert(temp.end(), r, end);
    std::move(temp.begin(), temp.end(), begin);
}
template<class Iterator, class Compare>
void mergeSort(const Iterator& begin, const Iterator& end, const Compare& compare) {
    int size = std::distance(begin, end);   
    if (size <= 1) { return; }
    Iterator mid = std::next(begin, size / 2);
    mergeSort(begin, mid, compare); // sort left half
    mergeSort(mid, end, compare); // sort right half
    mniu::inplace_merge(begin, mid, end, compare); // merge left and right. `std::implace_merge()`
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
void quickSort(const Iterator& begin, const Iterator& end, const Compare& compare) {
    if (begin == end) { return; }
    auto mid = mniu::partition(begin, end, compare);
    quickSort(begin, mid, compare);
    quickSort(mid + 1, end, compare);
}
} // namespace mniu

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        auto less = [](const auto& a, const auto& b){return a < b;};
        mniu::mergeSort(nums.begin(), nums.end(), less);
        // mniu::quickSort(nums.begin(), nums.end(), less);
        return nums;
    }
};
