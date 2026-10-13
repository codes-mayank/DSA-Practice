class SnapshotArray {
public:
    int cur = 0;
    vector<vector<pair<int, int>>> changes;

    SnapshotArray(int length) {
        changes.resize(length);
    }
    
    void set(int index, int val) {
        if (!changes[index].empty() && changes[index].back().first == cur) {
            changes[index].back().second = val;
        }
        else {
            changes[index].push_back({cur, val});
        }
    }
    
    int snap() {
        cur++;
        return cur-1;
    }
    
    int get(int index, int snap_id) {
        int idx = upper_bound(changes[index].begin(), changes[index].end(), make_pair(snap_id, INT_MAX)) - changes[index].begin();
        if (idx == 0) return 0;
        return changes[index][idx-1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */