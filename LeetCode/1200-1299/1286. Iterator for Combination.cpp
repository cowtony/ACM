class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength): s(characters) {
        sort(s.begin(), s.end());
        for (int i = 0; i < combinationLength; i++) {
            pointer.push_back(i);
        }
        pointer.back()--; // To adapt the first next().
    }
    
    string next() {
        for (int i = pointer.size() - 1, j = s.size() - 1; i >= 0; i--, j--) {
            if (pointer[i] < j) {
                pointer[i]++;
                for (int k = i + 1; k < pointer.size(); k++) {
                    pointer[k] = pointer[k - 1] + 1;
                }
                break;
            }
        }
        string res;
        for (int index : pointer) {
            res += s[index];
        }
        return res;
    }
    
    bool hasNext() const {
        for (int i = pointer.size() - 1, j = s.size() - 1; i >= 0; i--, j--) {
            if (pointer[i] < j) {
                return true;
            }
        }
        return false;
    }
    
    
private:
    string s;
    vector<int> pointer;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
