/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        s_begin.push(nestedList.begin());
        s_end.push(nestedList.end());
    }

    // @return {int} the next element in the iteration
    int next() {
        return (s_begin.top()++)->getInteger();
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        while (!s_begin.empty()) {
            if (s_begin.top() == s_end.top()) {
                s_begin.pop();
                s_end.pop();
            } else if (s_begin.top()->isInteger()) {
                return true;
            } else {
                auto x = s_begin.top();
                s_begin.top()++;
                s_begin.push(x->getList().begin());
                s_end.push(x->getList().end());
            }
        }
        return false;
    }
private:
    stack<vector<NestedInteger>::const_iterator> s_begin;
    stack<vector<NestedInteger>::const_iterator> s_end;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */
