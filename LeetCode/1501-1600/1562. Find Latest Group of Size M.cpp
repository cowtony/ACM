class UnionFind {
public:
    UnionFind(int n) : father(n), data(n, 0) {
        for (int i = 0; i < father.size(); i++) {
            father[i] = i;
        }
        count = n;
    }
    void connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra != rb) {
            data[rb] += data[ra];
            father[ra] = rb;
            count--;
        }
    }
    int root(int a) {
        if (father[a] == a) { return a; } 
        else { return father[a] = root(father[a]); }
    }
    int getData(int a) {
        return data[root(a)];
    }
    
    int count;
    vector<int> father;
    vector<int> data; // Store count of children.
};

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        UnionFind uf(arr.size() + 2);
        int count = 0;
        int last_step = -1;
        
        for (int i = 0; i < arr.size(); i++) {
            uf.data[arr[i]] = 1;
            
            if (uf.data[arr[i] - 1] > 0) {
                if (uf.getData(arr[i] - 1) == m) {
                    count--;
                }
                uf.connect(arr[i], arr[i] - 1);
            }
            if (uf.data[arr[i] + 1] > 0) {
                if (uf.getData(arr[i] + 1) == m) {
                    count--;
                }
                uf.connect(arr[i], arr[i] + 1);
            }
            if (uf.data[uf.root(arr[i])] == m) {
                count++;
            }
            
            if (count > 0) {
                last_step = i + 1;
            }
        }
        
        return last_step;
    }
};
