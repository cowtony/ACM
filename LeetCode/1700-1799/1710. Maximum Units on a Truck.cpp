class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& type1, const vector<int>& type2){
            return type1[1] > type2[1];
        });
        
        int res = 0;
        for (const vector<int>& boxType : boxTypes) {
            if (boxType[0] <= truckSize) {
                res += boxType[0] * boxType[1];
                truckSize -= boxType[0];
            } else {
                return res + truckSize * boxType[1];
            }
        }
        return res;
    }
};
