class Memcache {
public:
    Memcache() {
        // do intialization if necessary
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @return: An integer
     */
    int get(int curtTime, int key) {
        if (data.find(key) == data.end()) {
            return 2147483647;
        } else {
            if (data.at(key).first < curtTime) {
                data.erase(key);
                return 2147483647;
            } else {
                return data.at(key).second;
            }
        }
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @param value: An integer
     * @param ttl: An integer
     * @return: nothing
     */
    void set(int curtTime, int key, int value, int ttl) {
        if (ttl == 0) {
            data[key] = make_pair(INT_MAX, value);
        } else {
            data[key] = make_pair(curtTime + ttl - 1, value);
        }
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @return: nothing
     */
    void del(int curtTime, int key) {
        data.erase(key);
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @param delta: An integer
     * @return: An integer
     */
    int incr(int curtTime, int key, int delta) {
        if (data.find(key) == data.end()) {
            return 2147483647;
        } else {
            if (data.at(key).first < curtTime) {
                data.erase(key);
                return 2147483647;
            } else {
                data[key].second += delta;
                return data.at(key).second;
            }
        }
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @param delta: An integer
     * @return: An integer
     */
    int decr(int curtTime, int key, int delta) {
        if (data.find(key) == data.end()) {
            return 2147483647;
        } else {
            if (data.at(key).first < curtTime) {
                data.erase(key);
                return 2147483647;
            } else {
                data[key].second -= delta;
                return data.at(key).second;
            }
        }
    }
private:
    unordered_map<int, pair<int, int>> data; // key - [timeout_time, value]
};
