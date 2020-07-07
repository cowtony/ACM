class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : size_(size) {
        
    }
    
    double next(int val) {
        window.push_back(val);
        sum += val;
        if (window.size() > size_) {
            sum -= window.front();
            window.pop_front();
        }
        return double(sum) / window.size();
    }
    
private:
    int size_;
    int sum = 0;
    deque<int> window;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
