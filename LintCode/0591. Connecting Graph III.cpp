class ConnectingGraph3 {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
     ConnectingGraph3(int n) {
        father = vector<int>(n + 1);
        for (int i = 1; i <= n; i++) {
            father[i] = i;
        }
        total = n;
    }
    void connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra != rb) {
            father[ra] = rb;
            total--;
        }
    }

    /**
     * @return: An integer
     */
    int query() {
        return total;
    }
private:
    int root(int a) {
        if (father[a] == a) {
            return a;
        }
        return father[a] = root(father[a]);
    }
    int total;
    vector<int> father;
};
