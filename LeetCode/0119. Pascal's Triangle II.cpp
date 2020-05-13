class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        for (int i = 0; i <= rowIndex; i++)
        {
            for (int j = 0; j < i - 1; j++)
            {
                result[j] += result[j + 1];
            }
            result.insert(result.begin(), 1);
        }
        return result;
    }
};
