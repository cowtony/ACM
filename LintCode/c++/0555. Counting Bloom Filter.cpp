class CountingBloomFilter {
public:
    /*
    * @param k: An integer
    */CountingBloomFilter(int k) {
        array = vector<int>(kSize, 0);
        
        for (int i = 0; i < k ; i++) {
            hash_funcs[i] = ([i, this](string s){ return hash(s, i); });
        }
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void add(string &word) {
        for (auto func : hash_funcs) {
            array[func.second(word)]++;
        }
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void remove(string &word) {
        for (auto func : hash_funcs) {
            array[func.second(word)]--;
        }
    }

    /*
     * @param word: A string
     * @return: True if contains word
     */
    bool contains(string &word) {
        for (auto func : hash_funcs) {
            if (array[func.second(word)] <= 0) {
                return false;
            }
        }
        return true;
    }

private:
    const int kSize = 100000;
    vector<int> array;
    unordered_map<int, function<int(string)>> hash_funcs;
    
    int hash(string s, int salt) const {
        unsigned long hash_val = 5381 * salt;
        for (char c : s) {
            hash_val = ((hash_val << 5) + hash_val) + c; /* hash * 33 + c */
        }
        return hash_val % kSize;
    }
};
