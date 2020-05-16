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
class Solution {
public:
    int depthSum(const vector<NestedInteger>& nestedList) {
        stack<vector<NestedInteger>::const_iterator> begins;
        stack<vector<NestedInteger>::const_iterator> ends;
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
        
        int sum = 0;
        while (!begins.empty()) {
            if (begins.top() == ends.top()) {
                begins.pop();
                ends.pop();
                continue;
            }
            if (begins.top()->isInteger()) {
                sum += begins.size() * begins.top()->getInteger();
                begins.top()++;
            } else {
                const vector<NestedInteger>& list = begins.top()->getList();
                begins.top()++;
                begins.push(list.begin());
                ends.push(list.end());
            }
        }
        
        return sum;
    }
};
