class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < numbers.size(); i++) {
            if (m.find(numbers.at(i)) == m.end()) {
                m[target - numbers.at(i)] = i;
            } else {
                return {m[numbers.at(i)], i};
            }
        }
        return {};
    }
};
