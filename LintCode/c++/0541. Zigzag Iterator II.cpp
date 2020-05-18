class ZigzagIterator2 {
public:
    /*
    * @param vecs: a list of 1d vectors
    */ZigzagIterator2(vector<vector<int>>& vecs) {
        for (const auto& vec : vecs) {
            if (vec.begin() != vec.end()) {
                begins.push(vec.begin());
                ends.push(vec.end());
            }
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
 * Your ZigzagIterator2 object will be instantiated and called as such:
 * ZigzagIterator2 solution(vecs);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */
