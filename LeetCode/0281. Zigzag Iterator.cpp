class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.begin() != v1.end()) {
            begins.push(v1.begin());
            ends.push(v1.end());
        }
        if (v2.begin() != v2.end()) {
            begins.push(v2.begin());
            ends.push(v2.end());
        }
    }

    int next() {
        auto begin = begins.front();
        begins.pop();
        auto end = ends.front();
        ends.pop();
        int val = *begin;
        ++begin;
        if (begin != end) {
            begins.push(begin);
            ends.push(end);
        }
        return val;
    }

    bool hasNext() {
        return !begins.empty();
    }
    
private:
    queue<vector<int>::const_iterator> begins;
    queue<vector<int>::const_iterator> ends;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
