class Solution {
public:
    /**
     * @param sets: Initial set list
     * @return: The final number of sets
     */
    int setUnion(vector<vector<int>> &sets) {
        for (const vector<int>& nums : sets) {
            add(nums[0]);
            for (int i = 1; i < nums.size(); i++) {
                add(nums[i]);
                connect(nums[i - 1], nums[i]);
            }
        }
        return count;
    }
private:
    int count = 0;
    unordered_map<int, int> father;
    
    void add(int a) {
        if (father.find(a) == father.end()) {
            father[a] = a;
            count++;
        }
    }
    void connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra != rb) {
            father[ra] = rb;
            count--;
        }
    }
    int root(int a) {
        if (father[a] == a) {
            return a;
        } else {
            return father[a] = root(father[a]);
        }
    }
};
