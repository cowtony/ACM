#include "segment_tree.h"
#include "binary_indexed_tree.h"

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    // 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    SegmentTree       st_norm(0, 10, 1);
    LazySegmentTree   st_lazy(0, 10, 1);
    BinaryIndexedTree bi_tree(10);
    for (int i = 0; i < 10; i++) {
        bi_tree.add(i, 1);
        cout << st_norm.query(i, i) - 1;
        cout << st_lazy.query(i, i) - 1;
        cout << bi_tree.query(i, i) - 1 << endl;
    }

    cout << st_norm.query(0, 10) - 11 << st_lazy.query(0, 10) - 11 << endl;

    // 0, 0, 1, 1, 1, 1, 1, 1, 1, 1
    st_norm.update(0, 1, -1);
    cout << st_norm.query(0, 2) - 1 << st_norm.query(1, 1) - 0 << st_norm.query(1, 3) - 2 << endl;
    st_lazy.update(0, 1, -1);
    cout << st_lazy.query(0, 2) - 1 << st_lazy.query(1, 1) - 0 << st_lazy.query(1, 3) - 2 << endl;
    bi_tree.add(0, -1);
    bi_tree.add(1, -1);
    cout << bi_tree.query(0, 2) - 1 << bi_tree.query(1, 1) - 0 << bi_tree.query(1, 3) - 2 << endl;

    // 0, 5, 6, 6, 1, 1, 1, 1, 1, 1
    st_norm.update(1, 3, 5);
    st_lazy.update(1, 3, 5);
    bi_tree.add(1, 5);
    bi_tree.add(2, 5);
    bi_tree.add(3, 5);
    // 0, 5, 6, 4, -1, 1, 1, 1, 1, 1
    st_norm.update(3, 4, -2);
    cout << st_norm.query(0, 2) - 11 << st_norm.query(1, 1) - 5 << st_norm.query(1, 5) - 15 << endl;
    st_lazy.update(3, 4, -2);
    cout << st_lazy.query(0, 2) - 11 << st_lazy.query(1, 1) - 5 << st_lazy.query(1, 5) - 15 << endl;
    bi_tree.add(3, -2);
    bi_tree.add(4, -2);
    cout << bi_tree.query(0, 2) - 11 << bi_tree.query(1, 1) - 5 << bi_tree.query(1, 5) - 15 << endl; 

    return 0;
}