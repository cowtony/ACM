class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = events.lower_bound(start);
        if (it != events.end() and it->first < end) {
            return false;
        }
        if (it != events.begin() and (--it)->second > start) {
            return false;
        }
        
        events.emplace(start, end);
        return true;
    }
private:
    map<int, int> events;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
