class Solution {
public:
    /**
     * @param J: the types of stones that are jewels
     * @param S: representing the stones you have
     * @return: how many of the stones you have are also jewels
     */
    int numJewelsInStones(string &J, string &S) {
        unordered_set<char> jewels;
        for (char c : J) {
            jewels.insert(c);
        }
        int count = 0;
        for (char c : S) {
            if (jewels.find(c) != jewels.end()) {
                count++;
            }
        }
        return count;
    }
};
