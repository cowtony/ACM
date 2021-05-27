class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (last_printed.find(message) == last_printed.end() or timestamp - last_printed[message] >= 10) {
            last_printed[message] = timestamp;
            return true;
        } else {
            return false;
        }
    }

private:
    unordered_map<string, int> last_printed;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
