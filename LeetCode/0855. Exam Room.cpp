class ExamRoom {
public:
    ExamRoom(int N) {
        this->N = N;
        seated.insert(-1);
        seated.insert(N);
        empties.insert({-1, N, distance(-1, N)});
    }
    
    int seat() {
        auto [left, right, len] = *empties.begin();
        empties.erase(empties.begin());
        
        int res;
        if (left == -1) {
            res = 0;
        } else if (right == N) {
            res = N - 1;
        } else {
            res = left + (right - left) / 2;
        }
        
        empties.insert({left, res, distance(left, res)});
        empties.insert({res, right, distance(res, right)});
        seated.insert(res);
        return res;
    }
    
    void leave(int p) {
        auto it = seated.find(p);
        int left = *(--it);
        int right = *(++(++it));
        seated.erase(p);
        
        empties.erase({left, p, distance(left, p)});
        empties.erase({p, right, distance(p, right)});
        empties.insert({left, right, distance(left, right)});
    }
    
private:
    struct Node {
        int left;
        int right;
        int len; 
        bool operator < (const Node& n) const {
            if (len == n.len) {
                return left < n.left;
            } else {
                return len > n.len;
            }
        }
    };
    
    int N;
    set<Node> empties;
    set<int> seated;
    
    int distance(int left, int right) const {
        if (left == -1 or right == N) {
            return right - left - 2;
        } else {
            return (right - left) / 2 - 1;
        }
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
