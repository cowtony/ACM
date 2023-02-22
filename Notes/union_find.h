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

    int getSize(const Node& a) { return components[root(a)].size(); }
    const unordered_set<Node>& getNodesOf(const Node& a) { return components[root(a)]; }

  private:
    unordered_map<Node, Node> father;
    unordered_map<Node, unordered_set<Node>> components;  // Store all nodes connected as a component.
};

// Union Find with vector.
class UnionFind {
  public:
    UnionFind(int n) : father(n), size(n, 1) {
        for (int i = 0; i < father.size(); ++i) {
            father[i] = i;
        }
        count = n;
    }
    void connect(int a, int b) {
        if (a > b) { swap(a, b); }
        int ra = root(a);
        int rb = root(b);
        if (ra != rb) {
            size[ra] += size[rb];
            // TODO: process `data` here.
            father[rb] = ra;
            count--;
        }
    }
    int root(int x) {
        if (father[x] == x) { return x; } 
        else { return father[x] = root(father[x]); }
    }
    int getSize(int x) {
        return size[root(x)];
    }
  private:
    int count;        // Number of distinct component.
    vector<int> father;
    vector<int> size; // Store count of the component.
    vector<int> data; // Can add other data here.
};
