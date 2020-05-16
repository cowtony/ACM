template <class T>
struct DListNode {
    T data;
    DListNode* pre = nullptr;
    DListNode* next = nullptr;
};

template <class T>
class DLinkedList {
public:
    DListNode<T>* head() const { return head_; }
    DListNode<T>* tail() const { return tail_; }
    bool empty() const { return head_ == nullptr; }
    T pop_back(bool hard = false) { return erase(tail_, hard); }
    
    void push_front(DListNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        node->pre = nullptr;
        node->next = nullptr;
        if (head_) {
            head_->pre = node;
            node->next = head_;
            head_ = node;
        } else {
            head_ = node;
            tail_ = node;
        }
    }    
    
    T erase(DListNode<T>* node, bool hard = false) {
        if (node->pre) {
            node->pre->next = node->next;
        } else {
            head_ = node->next;
        }
        if (node->next) {
            node->next->pre = node->pre;
        } else {
            tail_ = node->pre;
        }
        T data = node->data;
        if (hard) {
            delete node;
        }
        return data;
    }

private:
    DListNode<T> *head_ = nullptr, *tail_ = nullptr;
};

class LFUCache {
public:
    /*
    * @param capacity: An integer
    */LFUCache(int capacity) {
        max_size = capacity;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        if (max_size <= 0) {
            return;
        }
        if (data.find(key) != data.end()) {
            get(key); // Add frequency by 1.
            data[key]->data.value = value;
            return;
        }
        if (data.size() == max_size) {
            DListNode<N>* node = frequency.begin()->second.tail();
            int freq = node->data.frequency;
            data.erase(node->data.key);
            frequency.at(freq).erase(node, true);
        }
        
        DListNode<N>* node = new DListNode<N>{{key, value, 0}};
        data[key] = node;
        frequency[0].push_front(node);
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        if (data.find(key) == data.end()) {
            return -1;
        }
        DListNode<N>* node = data.at(key);
        frequency.at(node->data.frequency).erase(node);
        if (frequency.at(node->data.frequency).empty()) {
            frequency.erase(node->data.frequency);
        }
        node->data.frequency++;
        frequency[node->data.frequency].push_front(node);
        return node->data.value;
    }
    
private:
    struct N {
        int key;
        int value;
        int frequency = 0;
    };
    int max_size;
    unordered_map<int, DListNode<N>*> data; // <key, Node*>
    map<int, DLinkedList<N>> frequency; // <frequency, DLinkedList>
};


