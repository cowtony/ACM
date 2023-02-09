class AllOne {
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        list<Bucket>::iterator it2 = buckets_.begin();
        int count = 0;
        if (key_to_bucket_.find(key) != key_to_bucket_.end()) {
            list<Bucket>::iterator it = key_to_bucket_.at(key);
            count = it->count;
            it2 = next(it, 1);
            it->keys.erase(key);
            if (it->keys.empty()) {
                buckets_.erase(it);
            }
        }

        if (it2 == buckets_.end() || it2->count > count + 1) {
            it2 = buckets_.insert(it2, {count + 1, {}});
        }
        it2->keys.insert(key);
        key_to_bucket_[key] = it2;
    }
    
    void dec(string key) {
        auto it = key_to_bucket_.at(key);
        if (it->count > 1) {
            auto it2 = prev(it, 1);
            if (it2 == buckets_.end() || it2->count < it->count - 1) {
                it2 = buckets_.insert(it, {it->count - 1, {}});
            }
            it2->keys.insert(key);
            key_to_bucket_[key] = it2;
        } else {
            key_to_bucket_.erase(key);
        }
        it->keys.erase(key);
        if (it->keys.empty()) {
            buckets_.erase(it);
        }
    }
    
    string getMaxKey() {
        if (buckets_.rbegin() == buckets_.rend()) {
            return "";
        }
        return *buckets_.rbegin()->keys.begin();
    }
    
    string getMinKey() {
        if (buckets_.begin() == buckets_.end()) {
            return "";
        }
        return *buckets_.begin()->keys.begin();
    }

private:
    struct Bucket {
        int count;
        unordered_set<string> keys;
    };
    list<Bucket> buckets_;
    unordered_map<string, list<Bucket>::iterator> key_to_bucket_;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
