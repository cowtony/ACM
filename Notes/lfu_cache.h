template<class K = int, class V = int>
class LFUCache {
public:
    LFUCache(int capacity) {
        max_size = capacity;
    }
    
    int get(int key) {
        if (data.find(key) == data.end()) {
            return -1;
        }
        updateFrequency(key);
        return data[key]->value;
    }
    
    void put(int key, int value) {
        if (max_size <= 0) {
            return;
        }
        if (data.find(key) != data.end()) {
            updateFrequency(key);
            data[key]->value = value;
        } else {
            if (data.size() == max_size) {
                eraseNode(--frequency.at(min_frequency).end());
            }
            addNode({key, value, 1});
            min_frequency = 1;
        }
    }

private:
    struct Node {
        int key;
        int value;
        int frequency = 1;
    };
    
    int max_size;
    int min_frequency = 0;
    unordered_map<int, list<Node>::iterator> data; // <key, Node*>
    unordered_map<int, list<Node>> frequency; // <frequency, DLinkedList>
    
    void updateFrequency(int key) {
        if (data.find(key) == data.end()) {
            return;
        }
        list<Node>::const_iterator it = data.at(key);
        Node node = *it; 
        eraseNode(it);
        node.frequency++;
        addNode(node);
    }
    
    void eraseNode(const list<Node>::const_iterator& it) {
        int freq = it->frequency;
        data.erase(it->key);
        frequency[freq].erase(it);
        if (frequency[freq].empty()) {
            frequency.erase(freq);
            if (freq == min_frequency) {
                min_frequency++;
            }
        }
    }
    
    void addNode(const Node& node) {
        frequency[node.frequency].emplace_front(node);
        data[node.key] = frequency[node.frequency].begin();
    }
};
