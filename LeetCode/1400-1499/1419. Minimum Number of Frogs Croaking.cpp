class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        const unordered_map<char, int> kCroak = {{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
        vector<int> count(5, 0);
        
        for (char c : croakOfFrogs) {
            int index = kCroak.at(c);

            count[index]++;
            if (index > 0) {
                count[index - 1]--;
                if (count[index - 1] < 0) {
                    return -1;
                }
            } else if (count[4] > 0) {
                count[4]--;
            }
        }

        if (count[0] | count[1] | count[2] | count[3] == 0) {
            return count[4];
        } else {
            return -1;
        }
    }
};
