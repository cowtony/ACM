class CustomStack {
public:
    CustomStack(int maxSize) {
        data.reserve(maxSize);
        count = 0;
        maxSize_ = maxSize;
    }
    
    void push(int x) {
        if (count < maxSize_) {
            data[count] = x;
            count++;
        }
    }
    
    int pop() {
        if (count > 0) {
            count--;
            return data[count];
        } else {
            return -1;
        }
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < k and i < count; i++) {
            data[i] += val;
        }
    }
    
    vector<int> data;
    int count;
    int maxSize_;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
