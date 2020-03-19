class ConnectingGraph {
public:
    /*
    * @param n: An integer
    */
    ConnectingGraph(int n) {
        // do intialization if necessary
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra != rb) {
            father[ra] = rb;
        }
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: A boolean
     */
    bool query(int a, int b) {
        return root(a) == root(b);
    }
private:
    unordered_map<int, int> father;
    
    int root(int a) {
        if (father.find(a) == father.end()) {
            return a;
        }
        return father[a] = root(father[a]);
    }
};
