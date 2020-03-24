// LeetCode 155: https://leetcode.com/problems/min-stack/
class MinStack {
public:
    MinStack() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        s.push(number);
        if (s_min.empty()) {
            s_min.push(number);
        } else {
            s_min.push(std::min(number, s_min.top()));
        }
    }

    /*
     * @return: An integer
     */
    int pop() {
        int num = s.top();
        s.pop();
        s_min.pop();
        return num;
    }

    /*
     * @return: An integer
     */
    int min() {
        return s_min.top();
    }
private:
    stack<int> s;
    stack<int> s_min;
};
