class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        row_begin = vec2d.begin();
        row_end = vec2d.end();
        if (row_begin != row_end) {
            col_begin = row_begin->begin();
            col_end = row_begin->end();
        }
    }

    int next() {
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
    vector<vector<int>>::iterator row_begin, row_end;
    vector<int>::iterator col_begin, col_end;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
