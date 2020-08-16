class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.begin() != v1.end()) {
            vectors.push({v1.begin(), v1.end()});
        }
        if (v2.begin() != v2.end()) {
            vectors.push({v2.begin(), v2.end()});
        }
    }

    int next() {
        auto [begin, end] = vectors.front();
        vectors.pop();
        int val = *begin;
        ++begin;
        if (begin != end) {
            vectors.push({begin, end});
        }
        return val;
    }

    bool hasNext() {
        return !vectors.empty();
    }
    
private:
    queue<pair<vector<int>::const_iterator, vector<int>::const_iterator>> vectors; // begin, end
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
