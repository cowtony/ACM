class MyQueue {
public:
    MyQueue() {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        input.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        int res = top();
        output.pop();
        return res;
    }

    /*
     * @return: An integer
     */
    int top() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

private:
    stack<int> input, output;
};
