class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> dishes;
        map<int, unordered_map<string, int>> tables; // Key = table No, Value = <Dish, count>
        for (vector<string> order : orders) {
            tables[stoi(order[1])][order[2]]++;
            dishes.insert(order[2]);
        }
        
        vector<vector<string>> ret;
        vector<string> first_row;
        first_row.push_back("Table");
        for (string dish : dishes) {
            first_row.push_back(dish);
        }
        ret.push_back(first_row);
        
        for (auto& [table_id, dish_count] : tables) {
            vector<string> row;
            row.push_back(to_string(table_id));
            
            for (string dish : dishes) {
                row.push_back(to_string(dish_count[dish]));
            }
            ret.push_back(row);
        }
        return ret;
    }
};
