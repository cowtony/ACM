namespace mniu {
template<class Iterator, class Compare>
void inplace_merge(const Iterator& begin, const Iterator& mid, const Iterator& end, 
                  Compare& compare) {
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
void mergeSort(const Iterator& begin, const Iterator& end, 
               Compare compare) {
    int size = std::distance(begin, end);   
    if (size <= 1) { return; }
    Iterator mid = std::next(begin, size / 2);
    mergeSort(begin, mid, compare); // sort left half
    mergeSort(mid, end, compare); // sort right half
    mniu::inplace_merge(begin, mid, end, compare); // merge left and right. `std::implace_merge()`
}
} // namespace mniu

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        mniu::mergeSort(logs.begin(), logs.end(), 
        [](const string& a, const string& b) {
            string a1 = a.substr(0, a.find(' '));
            string a2 = a.substr(a.find(' ') + 1);
            string b1 = b.substr(0, b.find(' '));
            string b2 = b.substr(b.find(' ') + 1);
            
            if (a2[0] >= '0' and a2[0] <= '9' and b2[0] >= '0' and b2[0] <= '9') {
                return false;
            } else if (b2[0] >= '0' and b2[0] <= '9') {
                return true;
            } else if (a2[0] >= '0' and a2[0] <= '9') {
                return false;
            } else {
                if (a2 == b2) {
                    return a1 < b1;
                } else {
                    return a2 < b2;
                }
            }
        });
        return logs;
    }
};
