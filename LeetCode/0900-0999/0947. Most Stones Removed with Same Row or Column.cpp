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

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf;

        for (const auto& stone : stones) {
            uf.connect(stone[0], stone[1] + 100000);
        }

        return stones.size() - uf.size();
    }
};
