class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        events[start]++;
        events[end]--;
        int sum = 0;
        for (auto it = events.begin(); it != events.end() and it->first < end; it++) {
            sum += it->second;
            if (sum > 2) {
                events[start]--;
                events[end]++;
                return false;
            }
        }
        return true;
    }

private:
    map<int, int> events;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
