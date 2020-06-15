class LRUCache {
public:
    LRUCache(int capacity) {
        max_size = capacity;
    }
    
    int get(int key) {
        if (data.find(key) == data.end()) {
            return -1;
        }
        auto it = data.at(key).first;
        frequent.push_front(*it);
        frequent.erase(it);
        data[key].first = frequent.begin();
        return data.at(key).second;
    }
    
    void put(int key, int value) {
        if (data.find(key) != data.end()) {
            get(key);
            data[key].second = value;
            return;
        }
        if (frequent.size() == max_size) {
            int key = frequent.back();
            data.erase(key);
            frequent.pop_back();
        }
        frequent.push_front(key);
        data[key] = make_pair(frequent.begin(), value);
    }
    
private:
    int max_size;
    unordered_map<int, pair<list<int>::iterator, int>> data; // <key, <iterator, value>>
    list<int> frequent; // Store keys as doublely linked list.
};
