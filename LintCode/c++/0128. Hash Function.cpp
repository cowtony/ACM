class Solution {
public:
    /**
     * @param key: A string you should hash
     * @param HASH_SIZE: An integer
     * @return: An integer
     */
    int hashCode(string &key, int HASH_SIZE) {
        long long hash = 0;
        for (char c : key) {
            hash = hash * 33 + c;
            hash = hash % HASH_SIZE;
        }
        return hash;
    }
};
