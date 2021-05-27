class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet(): hash_set(kSize) {
        
    }
    
    void add(int key) {
        list<int>& l = hash_set[key % kSize];
        for (int value : l) {
            if (value == key) {
                return;
            }
        }
        l.push_back(key);
    }
    
    void remove(int key) {
        list<int>& l = hash_set[key % kSize];
        for (auto it = l.begin(); it != l.end(); it++) {
            if (*it == key) {
                l.erase(it);
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        list<int>& l = hash_set[key % kSize];
        for (int value : l) {
            if (value == key) {
                return true;
            }
        }
        return false;
    }

private:
    int kSize = 10000;
    vector<list<int>> hash_set;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
