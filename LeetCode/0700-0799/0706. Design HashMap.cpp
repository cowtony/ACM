class MyHashMap {
public:
    MyHashMap(): data(base) {}
    
    void put(int key, int value) {
        int h = hash(key);
        for (auto& [key_, value_] : data[h]) {
            if (key_ == key) {
                value_ = value;
                return;
            }
        }
        data[h].push_back({key, value});
    }
    
    int get(int key) {
        int h = hash(key);
        for (const auto& [key_, value_] : data[h]) {
            if (key_ == key) {
                return value_;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if (it->first == key) {
                data[h].erase(it);
                return;
            }
        }
    }

private:
    vector<list<pair<int, int>>> data;
    static const int base = 769;

    static int hash(int key) {
        return key % base;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
