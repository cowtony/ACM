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
            father[rb] = ra;
            size[ra] += size[rb];
            // TODO: process `data` here.
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
    unordered_map<int, vector<int>> getComponents() {
        unordered_map<int, vector<int>> result;
        for (int i = 0; i < father.size(); i++) {
            result[root(i)].push_back(i);
        }
        return result;
    }
  private:
    int count;        // Number of distinct component.
    vector<int> father;
    vector<int> size; // Store count of the component.
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf(s.length());
        for (const auto& pair : pairs) {
            uf.connect(pair[0], pair[1]);
        }
        
        for (const auto& [_, nodes] : uf.getComponents()) {
            string temp;
            for (int node : nodes) {
                temp += s[node];
            }
            sort(temp.begin(), temp.end());
            int i = 0;
            for (int node : nodes) {
                s[node] = temp[i++];
            }
        }
        return s;
    }
};
