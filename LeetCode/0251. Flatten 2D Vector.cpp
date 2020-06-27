class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
        row_begin = v.begin();
        row_end = v.end();
        if (row_begin != row_end) {
            col_begin = row_begin->begin();
            col_end = row_begin->end();
        }
    }
    
    int next() {
        hasNext();
        return *col_begin++;
    }
    
    bool hasNext() {
        if (row_begin == row_end) {
            return false;
        }
        while (col_begin == col_end) {
            row_begin++;
            if (row_begin == row_end) {
                return false;
            } else {
                col_begin = row_begin->begin();
                col_end = row_begin->end();
            }
        }
        return true;
    }
    
private:
    vector<vector<int>>::const_iterator row_begin, row_end;
    vector<int>::const_iterator col_begin, col_end;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
