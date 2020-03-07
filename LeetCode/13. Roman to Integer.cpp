class Solution {
public:
    int romanToInt(string s) {
        vector<int> series;
        for (char c: s)
        {
            switch (c)
            {
                case 'I': series.push_back(1);    break;
                case 'V': series.push_back(5);    break;
                case 'X': series.push_back(10);   break;
                case 'L': series.push_back(50);   break;
                case 'C': series.push_back(100);  break;
                case 'D': series.push_back(500);  break;
                case 'M': series.push_back(1000); break;
            }
        }
        
        int result = 0;
        for (int i = 0; i < series.size(); i++)
        {
            if (i < series.size() - 1 && series[i] < series[i + 1])
            {
                result += series[i + 1] - series[i];
                i++;
            }
            else
                result += series[i];
        }
        
        return result;
    }
};
