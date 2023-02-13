class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char, int> count1, count2;
        for (char c : word1) {
            count1[c]++;
        }
        for (char c : word2) {
            count2[c]++;
        }
        for (auto [c1, cnt1] : count1) {
            for (auto [c2, cnt2] : count2) {
                int after_c1 = count1.size();
                int after_c2 = count2.size();
                if (c1 != c2) {
                    if (cnt1 == 1) {
                        after_c1--;
                    }
                    if (cnt2 == 1) {
                        after_c2--;
                    }
                    if (count2.find(c1) == count2.end()) {
                        after_c2++;
                    }
                    if (count1.find(c2) == count1.end()) {
                        after_c1++;
                    }
                }
                if (after_c1 == after_c2) {
                    return true;
                }
            }
        }
        return false;
    }
};
