class StockSpanner {
public:
    StockSpanner() {
        mono_decrease.push(make_pair(INT_MAX, idx++));
    }
    
    int next(int price) {
        while (!mono_decrease.empty() and mono_decrease.top().first <= price) {
            mono_decrease.pop();
        }
        int larger_idx = mono_decrease.top().second;
        mono_decrease.push(make_pair(price, idx++));
        return idx - 1 - larger_idx;
    }

private:
    int idx = 0; // This variable can be deleted by using the second value to store sum the span.
    stack<pair<int, int>> mono_decrease; // value & index
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
