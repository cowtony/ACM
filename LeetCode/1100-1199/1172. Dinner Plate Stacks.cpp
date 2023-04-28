class DinnerPlates {
public:
    DinnerPlates(int capacity): kCapacity(capacity) {
        
    }
    
    void push(int val) {
        if (avaliable_stacks.empty()) {
            stacks.push_back(vector<int>());
            stacks.back().reserve(kCapacity);
            avaliable_stacks.insert(stacks.size() - 1);
        }
        stacks[*avaliable_stacks.begin()].push_back(val);
        if (stacks[*avaliable_stacks.begin()].size() == kCapacity) {
            avaliable_stacks.erase(avaliable_stacks.begin());
        }
    }
    
    int pop() {
        return popAtStack(stacks.size() - 1);
    }
    
    int popAtStack(int index) {
        if (stacks.size() <= index || stacks[index].empty()) {
            return -1;
        }
        int ret = stacks[index].back();
        stacks[index].pop_back();
        avaliable_stacks.insert(index);

        while (index >= 0 && stacks.size() - 1 == index && stacks[index].empty()) {
            stacks.pop_back();
            avaliable_stacks.erase(index);
            index--;
        }
        return ret;
    }

private:
    const int kCapacity;
    vector<vector<int>> stacks;
    set<int> avaliable_stacks;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
