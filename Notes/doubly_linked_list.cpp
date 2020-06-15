template <class T>
struct DoublyLinkedListNode {
    T data;
    DoublyLinkedListNode* pre = nullptr;
    DoublyLinkedListNode* next = nullptr;
};

template <class T>
class DoublyLinkedList {
public:
    DoublyLinkedListNode<T>* head() const { return head_; }
    DoublyLinkedListNode<T>* tail() const { return tail_; }
    int size() const { return size_; }
    bool empty() const { return head_ == nullptr; }
    T pop_back(bool hard = false) { return erase(tail_, hard); }
    
    void push_front(DoublyLinkedListNode<T>* node) {
        if (node == nullptr) { return; }
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
    
    T erase(DoublyLinkedListNode<T>* node, bool hard = false) {
        if (node == nullptr) { return T(); }
        if (node->pre) { node->pre->next = node->next; } 
        else { head_ = node->next; }
        if (node->next) { node->next->pre = node->pre; }
        else { tail_ = node->pre; }
        T data = node->data;
        if (hard) { delete node; }
        size_--;
        return data;
    }

private:
    int size_ = 0;
    DListNode<T> *head_ = nullptr, *tail_ = nullptr;
};
