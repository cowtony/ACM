class ConnectingGraph2 {
public:
    /*
    * @param n: An integer
    */
    ConnectingGraph2(int n) {
        // do intialization if necessary
        father = vector<int>(n + 1, -1);
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        a = root(a);
        b=  root(b);
        if (root(a) != root(b)) {
            father[b] += father[a];
            father[a] = b;
        }
    }

    /*
     * @param a: An integer
     * @return: An integer
     */
    int query(int a) {
        return -father[root(a)];
    }
    
private:
    vector<int> father;
    
    int root(int a) {
        if (father[a] > 0) {
            return father[a] = root(father[a]);
        } else {
            return a;
        }
    }
};
