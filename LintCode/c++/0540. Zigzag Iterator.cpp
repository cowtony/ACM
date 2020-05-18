class ZigzagIterator {
public:
    /*
    * @param v1: A 1d vector
    * @param v2: A 1d vector
    */ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.begin() != v1.end()) {
            begins.push(v1.begin());
            ends.push(v1.end());
        }
        if (v2.begin() != v2.end()) {
            begins.push(v2.begin());
            ends.push(v2.end());
        }
    }

    /*
     * @return: An integer
     */
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

    /*
     * @return: True if has next
     */
    bool hasNext() {
        return !begins.empty();
    }

private:
    queue<vector<int>::const_iterator> begins;
    queue<vector<int>::const_iterator> ends;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator solution(v1, v2);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */
