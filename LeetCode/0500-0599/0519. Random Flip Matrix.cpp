class Solution {
public:
    Solution(int m, int n) : kRow(m), kCol(n) {
        reset();
    }

    // Fisher–Yates shuffle
    vector<int> flip() {
        int r = rand() % remain;
        int result;
        if (pos.find(r) == pos.end()) {
            result = r;
        } else {
            result = pos[r];
        }
        remain--;
        // Assign the next avaliable index to pos[r] for collision avoidance.
        if (pos.find(remain) == pos.end()) {
            pos[r] = remain;
        } else {
            pos[r] = pos[remain];
        }
        
        return {result / kCol, result % kCol};
    }
    
    void reset() {
        remain = kRow *  kCol;
        pos.clear();
    }
private:
    const int kRow, kCol;
    int remain;
    unordered_map<int, int> pos;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
