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
    int size() const { return size_; }
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
        size_++;
    }    
    
    T erase(DListNode<T>* node, bool hard = false) {
        if (node == nullptr) {
            return T();
        }
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
        size_--;
        return data;
    }

private:
    int size_ = 0;
    DListNode<T> *head_ = nullptr, *tail_ = nullptr;
};

class LRUCache {
public:
    /*
    * @param capacity: An integer
    */LRUCache(int capacity) {
        max_size = capacity;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        if (data.find(key) == data.end()) {
            return -1;
        }
        // DListNode<Node> *node = data.at(key);
        frequent.erase(data.at(key));
        frequent.push_front(data.at(key));
        return data.at(key)->data.value;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        if (data.find(key) != data.end()) {
            get(key);
            data[key]->data.value = value;
            return;
        }
        if (frequent.size() == max_size) {
            auto* node = frequent.tail();
            data.erase(node->data.key);
            frequent.pop_back();
        }
        data[key] = new DListNode<Node>{{key, value}};
        frequent.push_front(data.at(key));
    }
    
private:
    struct Node {
        int key;
        int value;
    };
    int max_size;
    unordered_map<int, DListNode<Node>*> data; // <key, Node<value>>
    DLinkedList<Node> frequent;
};
