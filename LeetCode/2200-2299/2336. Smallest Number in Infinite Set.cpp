class SmallestInfiniteSet {
  public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1001; i++) {
            nums.insert(i);
        }
    }
    
    int popSmallest() {
        int i = *nums.begin();
        nums.erase(nums.begin());
        return i;
    }
    
    void addBack(int num) {
        nums.insert(num);
    }

  private:
    set<int> nums;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
