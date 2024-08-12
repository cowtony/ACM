class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k_(k) {
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (pq.size() < k_) {
            pq.push(val);
        } else if (pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
