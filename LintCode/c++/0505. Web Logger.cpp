class WebLogger {
public:
    WebLogger() {
        // do intialization if necessary
    }

    /*
     * @param timestamp: An integer
     * @return: nothing
     */
    void hit(int timestamp) {
        hits.push_back(timestamp);
    }

    /*
     * @param timestamp: An integer
     * @return: An integer
     */
    int get_hit_count_in_last_5_minutes(int timestamp) {
        while (!hits.empty() and hits.front() <= timestamp - 5 * 60) {
            hits.pop_front();
        }
        return hits.size();
    }

private:
    deque<int> hits;
};
