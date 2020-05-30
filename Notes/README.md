# Data Structure
## Array
### Prefix Sum
1D template
2D template
### Binary Indexed Tree (Fenwick Tree)

## Linked List
- Recursive.
- [Trick] Slow-Fast pointer: when slow pointer move 1 step, fast pointer move 2 steps. Noramlly used for checking if a loop exist. [876](https://leetcode.com/problems/middle-of-the-linked-list/), [141](https://leetcode.com/problems/linked-list-cycle/), [202](https://leetcode.com/problems/happy-number/)
```
template <class T>
struct DListNode {
    T data;
    DListNode* pre = nullptr;
    DListNode* next = nullptr;
};

template <class T>
class DLinkedList {
public:
    DListNode<T>* head() const { return head_; }
    DListNode<T>* tail() const { return tail_; }
    int size() const { return size_; }
    bool empty() const { return head_ == nullptr; }
    T pop_back(bool hard = false) { return erase(tail_, hard); }
    
    void push_front(DListNode<T>* node) {
        if (node == nullptr) { return; }
        node->pre = nullptr;
        node->next = nullptr;
        if (head_) {
            head_->pre = node;
            node->next = head_;
            head_ = node;
        } else {
            head_ = node;
            tail_ = node;
        }
        size_++;
    }    
    
    T erase(DListNode<T>* node, bool hard = false) {
        if (node == nullptr) { return T(); }
        if (node->pre) { node->pre->next = node->next; } 
        else { head_ = node->next; }
        if (node->next) { node->next->pre = node->pre; }
        else { tail_ = node->pre; }
        T data = node->data;
        if (hard) { delete node; }
        size_--;
        return data;
    }

private:
    int size_ = 0;
    DListNode<T> *head_ = nullptr, *tail_ = nullptr;
};
```
### \*Dancing Links
- A data structure to use back tracking to solve **Exact Cover** problems. [Sudoku](https://leetcode.com/problems/sudoku-solver/), [N Queens](https://leetcode.com/problems/n-queens/)
## Tree
- `Edge = Node - 1`
### Binary Search Tree (BST)
- BST to sorted array: Recursive. [1379](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/)
- Balanced BST (Red-Black Tree): Sorted Array to BBST: Use binary search + recursive. [108](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/), [1379](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/)
### Union Find 并查集 [589](https://www.lintcode.com/problem/connecting-graph/description) [590](https://www.lintcode.com/problem/connecting-graph-ii/description) [591](https://www.lintcode.com/problem/connecting-graph-iii/description)
- Data Storage: `father[i] = j;`, `father["child"] = "parent";`
- 路径压缩：在找顶点的同时把经过的点都指向顶点 O(n)->O(1)
- Store additional information at root. [Trick]: when node are positive integers, additional information can be stored as negative value.
- Cannot delete an edge.

[Code Template](Union_Find.cpp)

### Trie (Prefix Tree) 字典树 [442](https://www.lintcode.com/problem/implement-trie-prefix-tree/description)
[Code template](Trie.cpp)
### Segment Tree [LeetCode](https://leetcode.com/problemset/all/?topicSlugs=segment-tree)

### Inorder, Preorder, Postorder traversal [Template](tree.cpp)
#### Recursive
#### \*[Morris Traversal](https://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html)  [94](https://leetcode.com/problems/binary-tree-inorder-traversal/), [99](https://leetcode.com/problems/recover-binary-search-tree/)
Traverse a binary tree without using recursive and stack, this is needed when memory is limited.
## Heap (Priority Queue)
- [378](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)
## Stack
### Monotonic Stack 单调栈 [84](https://leetcode.com/problems/largest-rectangle-in-histogram/), [1438](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)
- 用于求比当前元素大（小）的下一个（前一个）元素。[questions](https://blog.csdn.net/qq_17550379/article/details/86519771)
- 用于求Moving Window的最大最小值 O(n).
- When the **maximum** value need to be maintained in stack, **decrease** stack should be used, vice versa.
- Sometimes store the index in stack instead of value.
## Deque (Double Ended Queue)
# Algorithm
## Recursive
- DFS / Backtracking
- Speed up: Memorize result. [87](https://leetcode.com/problems/scramble-string/)
- Speed up: Use more global variable than pass by argument.
## [Sort](Sort.cpp)
### Bubble Sort O(n^2)
### Counting Sort O(n)
Regular counting sort used when there are finite element types. [49](https://leetcode.com/problems/group-anagrams/), [75](https://leetcode.com/problems/sort-colors/)\
The follow sort algorithm break the finite element limitation:
#### Radix Sort O(nk)
#### Bucket Sort
[164](https://leetcode.com/problems/maximum-gap/)
### Merge Sort O(n log(n))
Merge sort will not change the order of the equal value. (Useful when compare by string length).
### Quick Sort O(n log(n))
- Recursively perform partition.
- [Partition / Quick Select O(n)](https://selfboot.cn/2016/09/01/lost_partition/): [Find Kth largest element](https://leetcode.com/problems/kth-largest-element-in-an-array/)
    
## Binary Search
- Search number from array.
- Overflow issue: Replace `middle = (low + high) / 2` with `middle = low + (high - low) / 2`.
- Bias middle: Use `middle = (low + high + 1) / 2` instead of `middle = (low + high) / 2` if you have `low = middle` instead of `low = middle + 1`. (Consider the case `low = 3, high = 4`, then `middle = 3` and using `low = middle` will not change anything.)
### Trial answer
when backward consider the question is much easier. [287](https://leetcode.com/problems/find-the-duplicate-number/), [644](https://leetcode.com/problems/maximum-average-subarray-ii/)
## Dynamic Programming (DP)
General steps:
1. Consider how to solve the problem for the last step. (Can you solve it with recursion + memorize?)
2. Find the transition equation/matrix: Is state `k` can be deduced from `k - 1`? Example: `answer[k] = f(answer[k - 1], array[k])`.
3. Determine the order of calculation.
4. Determine the initial condition.
- Space compress: use 1D array instead of 2D array, use variables instead of 1D array.
### 区间型动态规划 [312](https://leetcode.com/problems/burst-balloons/), [486](https://leetcode.com/problems/predict-the-winner/)
- Calculate order: short to long.
### String
### Knapsack
- One dimention for capacity.
## Graph
### Minimum Spanning Tree 最小生成树
- Kruskal Algorithm: Greedy + Union Find
- Prim Algorithm
### Shortest Path
- Floyd
- Dijkstra
## String
### \*[KMP (Knuth Morris Pratt)](https://blog.csdn.net/v_july_v/article/details/7041827) 
Find longest prefix == suffix [1392](https://leetcode.com/problems/longest-happy-prefix/), [28](https://leetcode.com/problems/implement-strstr/)
```
vector<int> longestPrefix(string s) {
    vector<int> next(s.length(), 0);
    for (int i = 0; i < s.length(); i++) {
        int pre = i;
        do {
            if (pre > 0) {
                pre = next[pre - 1];
                next[i] = pre + 1;
            } else {
                next[i] = 0;
                break;
            }
        } while (s[i] != s[pre]);
    }
    return next;
}
```
## Sweep Line
