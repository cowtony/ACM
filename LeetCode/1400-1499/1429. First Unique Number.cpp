class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            add(num);
        }
    }
    
    int showFirstUnique() {
        if (q.empty()) {
            return -1;
        } else {
            return q.front();
        }
    }
    
    void add(int value) {
        counter[value]++;
        q.push(value);
        while (!q.empty() and counter[q.front()] > 1) {
            q.pop();
        }
    }
private:
    unordered_map<int, int> counter;
    queue<int> q;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
