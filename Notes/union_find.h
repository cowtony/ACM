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
            for (const Node& n : component[ra]) {
                component[rb].insert(n);
            }
            component.erase(ra);
        }
        return rb;
    }
    
    // Find root with route compress.
    Node root(const Node& a) {
        if (father.find(a) == father.end()) { // New node seen.
            father[a] = a;
            component[a].insert(a);
        }
        if (father[a] == a) { return a; } 
        else { return father[a] = root(father[a]); }
    }

    int getSize(const Node& a) { return component[root(a)].size(); }
    const unordered_set<Node>& getNodesOf(const Node& a) { return component[root(a)]; }

  private:
    unordered_map<Node, Node> father;
    unordered_map<Node, unordered_set<Node>> component;  // Store all nodes connected as a component.
};

// Union Find with vector.
class UnionFind {
public:
    UnionFind(int n) : father(n), size(n, 1) {
        for (int i = 0; i < father.size(); i++) {
            father[i] = i;
        }
        count = n;
    }
    void connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra != rb) {
            size[rb] += size[ra];
            // TODO: process `data` here.
            father[ra] = rb;
            count--;
        }
    }
    int root(int a) {
        if (father[a] == a) { return a; } 
        else { return father[a] = root(father[a]); }
    }
    int getSize(int a) {
        return size[root(a)];
    }
    
    int count;
    vector<int> father;
    vector<int> size; // Store count of the component.
    vector<int> data; // Can add other data here.
};
