class LRUCache {
public:
    LRUCache(int capacity) {
        max_size = capacity;
    }
    
    int get(int key) {
        if (data.find(key) == data.end()) {
            return -1;
        }
        update(key);
        return data[key].second;
    }
    
    void put(int key, int value) {
        if (data.find(key) != data.end()) {
            update(key);
        } else {
            frequent.push_front(key);
        }
        data[key] = make_pair(frequent.begin(), value);
        if (frequent.size() > max_size) {
            data.erase(frequent.back());
            frequent.pop_back();
        }
    }
    
private:
    int max_size;
    unordered_map<int, pair<list<int>::iterator, int>> data; // <key, <iterator, value>>
    list<int> frequent; // Store keys as doublely linked list.
    
    void update(int key) {
        auto it = data.at(key).first;
        frequent.push_front(*it);
        frequent.erase(it);
        data[key].first = frequent.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
