class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefix_xor(arr.size() + 1, 0);
        for (int i = 0; i < arr.size(); i++) {
            prefix_xor[i + 1] = prefix_xor[i] ^ arr[i];   
        }
        
        int count = 0;
        // key: prefix_xor value, Value: list of index
        unordered_map<int, vector<int>> um; 
        um[prefix_xor[0]].push_back(0);
        um[prefix_xor[1]].push_back(1);
        for (int k = 2; k < prefix_xor.size(); k++) {
            if (um.find(prefix_xor[k]) != um.end()) {
                for (int i : um.at(prefix_xor[k])) {
                    count += k - i - 1;
                }
            }
            um[prefix_xor[k]].push_back(k);
        }
        
        return count;
    }
};
