/*
- Merge Sort.
- Merge K Sorted Arrays.
- Partition. (Quick Select)
- Quick Sort.
*/

// Merge Sort.
template<class Iterator>
void inplaceMerge(const Iterator& begin, const Iterator& mid, const Iterator& end) {
    std::vector<typename Iterator::value_type> temp;
    temp.reserve(std::distance(begin, end));
    Iterator l = begin;
    Iterator r = mid;
    while (l != mid and r != end) {
        if (*r < *l) { temp.emplace_back(*r++); }
        else { temp.emplace_back(*l++); }
    }
    temp.insert(temp.end(), l, mid);
    temp.insert(temp.end(), r, end);
    std::move(temp.begin(), temp.end(), begin);
}

template<class Iterator>
void mergeSort(const Iterator& begin, const Iterator& end) {
    int size = std::distance(begin, end);   
    if (size <= 1) { return; }
    Iterator mid = std::next(begin, size / 2);
    mergeSort(begin, mid); // sort left half
    mergeSort(mid, end); // sort right half
    inplaceMerge(begin, mid, end); // merge left and right. `std::implace_merge()`
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
        while(lo < hi && array[hi] >= pivot) { --hi; }
        array[lo] = array[hi];
        while(lo < hi && array[lo] <= pivot) { ++lo; }
        array[hi] = array[lo];
    }
    array[lo] = pivot;
    return lo;
}

// Quick Sort.


