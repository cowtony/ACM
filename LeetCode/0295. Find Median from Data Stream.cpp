class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (large.empty() or num <= large.top()) {
            large.push(num);
        } else {
            small.push(num);
        }
        // balance
        if (large.size() < small.size()) {
            large.push(small.top());
            small.pop();
        } else if (large.size() >= small.size() + 2) {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if (large.size() == small.size()) {
            return (large.top() + small.top()) / 2.0;
        } else {
            return large.top();
        }
    }
private:
    priority_queue<int, vector<int>, greater<int>> small;
    priority_queue<int> large;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
