// Union Find with unordered_map.
template <class T = int>
class UnionFind {
public:
    // The connect function will add new element automatically.
    void connect(const T& a, const T& b) {
        T ra = root(a);
        T rb = root(b);
        if (ra != rb) {
            root_data[rb] += root_data[ra];
            father[ra] = rb;
            root_data.erase(ra);
        }
    }
    
    // Find root with route compress.
    T root(const T& a) {
        if (father.find(a) == father.end()) { 
            father[a] = a;
            root_data[a] = 1;
        }
        if (father[a] == a) { return a; } 
        else { return father[a] = root(father[a]); }
    }
    int getData(const T& a) {
        return root_data[root(a)];
    }
    // Store all roots and properties such as size, max_value.
    unordered_map<T, int> root_data;
    unordered_map<T, T> father;
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
