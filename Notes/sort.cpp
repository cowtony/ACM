/*
- Merge Sort.
- Merge K Sorted Arrays.
- Partition. (Quick Select): Get smallest/largest k elements.
- Quick Sort.
*/

// Merge Sort.
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
    inplace_merge(begin, mid, end, compare); // merge left and right. `std::implace_merge()`
}

// Merge K Sorted Arrays.
template<class T>
vector<T> mergeSortedArrays(vector<vector<T>>& arrays) {
    struct Node {
        typename vector<T>::iterator current;
        typename vector<T>::const_iterator end;
        bool operator < (const Node& n) const {
            return *current > *n.current;
        }
    };
    priority_queue<Node> pq;
    for (vector<T>& array : arrays) {
        if (!array.empty()) {
            pq.push(Node{array.begin(), array.end()});
        }
    }

    vector<T> ret;
    while (!pq.empty()) {
        Node n = pq.top();
        pq.pop();
        ret.push_back(*n.current++);
        if (n.current != n.end) { pq.push(n); }
    }
    return ret;
}

// Partition
int partition(vector<int>& array, int pivot) {
    int lo = 0, hi = array.size() - 1;
    while(lo <= hi) {
        while(lo <= hi && array[hi] >= pivot) { --hi; }
        while(lo <= hi && array[lo] < pivot) { ++lo; }
        if (lo < hi) { swap(array[lo++], array[hi--]); }
    }
    return lo;
}
int partition(vector<int>& array, int lo, int hi) {
    int pivot = array[lo];
    while(lo < hi) {
        // --hi must go before ++lo to make sure array[lo] can be first replaced.
        while(lo < hi && array[hi] >= pivot) { --hi; }
        array[lo] = array[hi];
        while(lo < hi && array[lo] <= pivot) { ++lo; }
        array[hi] = array[lo];
    }
    array[lo] = pivot;
    return lo;
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

// TODO: introselect
template<class Iterator, class Compare>
void nth_element(Iterator begin, Iterator nth, Iterator end, const Compare& compare) {
    while (begin != end) {
        Iterator p = partition(begin, end, compare);
        if (distance(begin, p) < distance(begin, nth)) { begin = p + 1; }
        else { end = p; }
    }
}

// Quick Sort (with tail recursion).
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

