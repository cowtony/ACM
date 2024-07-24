class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, queue<int>> num_mapping;
        vector<int> result;
        for (int num : nums) {
            int converted = convert(mapping, num);
            num_mapping[converted].push(num);
            result.push_back(converted);
        }
        sort(result.begin(), result.end());

        for (int& num : result) {
            int tmp = num_mapping[num].front();
            num_mapping[num].pop();
            num = tmp;
        }
        return result;
    }

    int convert(const vector<int>& mapping, int num) {
        if (num == 0) {
            return mapping[0];
        }
        int result = 0;
        int base = 1;
        while (num) {
            int digit = mapping[num % 10];
            result += digit * base;
            num /= 10;
            base *= 10;
        }
        return result;
    }
};
