/**
 * Definition of Column:
 * class Column {
 * public:
 *     int key;
 *     String value;
 *     Column(int key, string value) {
 *         this->key = key;
 *         this->value = value;
 *    }
 * }
 */


class MiniCassandra {
public:
    MiniCassandra() {
        // do intialization if necessary
    }

    /*
     * @param row_key: a string
     * @param column_key: An integer
     * @param value: a string
     * @return: nothing
     */
    void insert(string &row_key, int column_key, string &value) {
        data[row_key][column_key] = value;
    }

    /*
     * @param raw_key: a string
     * @param column_start: An integer
     * @param column_end: An integer
     * @return: a list of Columns
     */
    vector<Column> query(string &row_key, int column_start, int column_end) {
        const map<int, string>& cols = data[row_key];
        vector<Column> ret;
        for (auto it = cols.lower_bound(column_start); it != cols.end() and it->first <= column_end; it++) {
            ret.push_back(Column(it->first, it->second));
        }
        return ret;
    }
private:
    unordered_map<string, map<int, string>> data;
};
