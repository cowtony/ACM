// Circular Buffer, producer - consumer
template<class T>
class Queue {
  public:
    Queue(int max_size) : kMaxSize(max_size), buffer(max_size) {
        size_ = 0;
        head_ = 0;
        tail_ = 0;
    }
    
    int size() const {
        return size_;
    }
    
    bool empty() const {
        return size() == 0;
    }
    
    std::pair<T, bool> top() const {
        if (empty()) {
            return {T(), false};
        }
        return {buffer.at(tail_), true};
    }
    
    void pop() {
        if (empty()) {
            return;
        }
        tail_ = (tail_ + 1) % kMaxSize;
        --size_;
    }
    
    void push(const T&& data) {
        if (size() == kMaxSize) {
            pop();
        }
        buffer[head_] = std::move(data);
        head_ = (head_ + 1) % kMaxSize;
        ++size_;
    }
    
    void resize(int new_size) {
        // TODO
    }
  
  private:
    const int kMaxSize;
    vector<T> buffer;
    int head_, tail_;
    int size_;
};
