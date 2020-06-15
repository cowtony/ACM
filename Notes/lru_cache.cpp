template<class K = int, class V = int>
class LRUCache {
public:
    LRUCache(int capacity) {
        max_size = capacity;
    }
    
    V get(K key) {
        if (data.find(key) == data.end()) {
            return V();
        }
        auto it = data.at(key).first;
        frequent.push_front(*it);
        frequent.erase(it);
        data[key].first = frequent.begin();
        return data.at(key).second;
    }
    
    V getOldest() const {
        if (frequent.empty()) {
            return V();
        }
        return data.at(frequent.back()).second;
    }
    
    void put(K key, V value) {
        if (data.find(key) != data.end()) {
            get(key);
            data[key].second = value;
            return;
        }
        if (frequent.size() == max_size) {
            K key = frequent.back();
            data.erase(key);
            frequent.pop_back();
        }
        frequent.push_front(key);
        data[key] = make_pair(frequent.begin(), value);
    }
    
private:
    int max_size;
    unordered_map<K, pair<typename list<K>::iterator, V>> data; // <key, <iterator, value>>
    list<K> frequent; // Store keys as doublely linked list. newest->oldest
};
