// Union Find with vector.
class UnionFind {
  public:
    UnionFind(int n) : father_(n), size_(n, 1), count(n) {
        for (int i = 0; i < father_.size(); ++i) {
            father_[i] = i;
        }
    }
    void connect(int a, int b) {
        if (a > b) { swap(a, b); }
        int ra = root(a);
        int rb = root(b);
        if (ra != rb) {
            father_[rb] = ra;
            size_[ra] += size_[rb];
            // TODO: process `data` here.
            count--;
        }
    }
    int root(int x) {
        if (father_[x] == x) { return x; } 
        else { return father_[x] = root(father_[x]); }
    }
    int size(int x) {
        return size_[root(x)];
    }
    unordered_map<int, vector<int>> getComponents() {
        unordered_map<int, vector<int>> result;
        for (int i = 0; i < father_.size(); i++) {
            result[root(i)].push_back(i);
        }
        return result;
    }

    int count;        // Number of distinct component.

  private:
    vector<int> father_;
    vector<int> size_; // Store count of the component.
};

// Union Find with unordered_map.
template <class Node = int>
class UnionFind {
  public:
    // The connect function will add new element automatically.
    Node connect(const Node& a, const Node& b) {
        Node ra = root(a);
        Node rb = root(b);
        if (ra != rb) {
            father[ra] = rb;
            for (const Node& n : components[ra]) {
                components[rb].insert(n);
            }
            components.erase(ra);
        }
        return rb;
    }
    
    // Find root with route compress.
    Node root(const Node& a) {
        if (father.find(a) == father.end()) { // New node seen.
            father[a] = a;
            components[a].insert(a);
        }
        if (father[a] == a) { return a; } 
        else { return father[a] = root(father[a]); }
    }

    int size() { return components.size(); }
    int size(const Node& a) { return components[root(a)].size(); }
    const unordered_set<Node>& getNodesOf(const Node& a) { return components[root(a)]; }

  private:
    unordered_map<Node, Node> father;
    unordered_map<Node, unordered_set<Node>> components;  // Store all nodes connected as a component.
};
