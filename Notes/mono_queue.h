class MonoQueue : public deque<int> {
  public:
    void pop_until(int idx) {
        while (!this->empty() && this->front() < idx) {
            this->pop_front();
        }
    }
    void add_back(int idx, const vector<int>& nums) {
        // <= Strict decrease, < decrease
        // >= Strict increase, > increase
        while (!this->empty() && nums[this->back()] <= nums[idx]) {
            this->pop_back();
        }
        this->push_back(idx);
    }
};
