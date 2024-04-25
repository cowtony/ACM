class SnapshotArray {
public:
    SnapshotArray(int length): snap_shot_array_(length, {{0, 0}}) {}
    
    void set(int index, int val) {
        snap_shot_array_[index][snap_id] = val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        return (--snap_shot_array_[index].upper_bound(snap_id))->second;
    }

private:
    int snap_id = 0;
    vector<map<int, int>> snap_shot_array_;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
