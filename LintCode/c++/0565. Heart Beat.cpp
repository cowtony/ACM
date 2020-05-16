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
    
    T erase(DListNode<T>* node, bool hard = false) {
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

class HeartBeat {
public:
    HeartBeat() {
        // do intialization if necessary
    }

    /*
     * @param slaves_ip_list: a list of slaves'ip addresses
     * @param k: An integer
     * @return: nothing
     */
    void initialize(vector<string> &slaves_ip_list, int k) {
        for (string slave_ip : slaves_ip_list) {
            slaves[slave_ip] = new DListNode<Node>{{0, slave_ip}};
            dls.push_front(slaves[slave_ip]);
        }
        interval = 2 * k;
    }

    /*
     * @param timestamp: current timestamp in seconds
     * @param slave_ip: the ip address of the slave server
     * @return: nothing
     */
    void ping(int timestamp, string &slave_ip) {
        if (slaves.find(slave_ip) == slaves.end()) {
            return;
        }
        DListNode<Node>* node = slaves.at(slave_ip);
        node->data.recent = timestamp;
        dls.erase(node);
        dls.push_front(node);
    }

    /*
     * @param timestamp: current timestamp in seconds
     * @return: a list of slaves'ip addresses that died
     */
    vector<string> getDiedSlaves(int timestamp) {
        vector<string> ret;
        DListNode<Node>* node = dls.tail();
        while (node) {
            if (node->data.recent <= timestamp - interval) {
                ret.push_back(node->data.ip);
            } else {
                break;
            }
            node = node->pre;
        }
        return ret;
    }
    
private:
    struct Node {
        int recent;
        string ip;
    };
    int interval;
    unordered_map<string, DListNode<Node>*> slaves;
    DLinkedList<Node> dls;
};
