/**
 * Definition of Input:
 * template<class T>
 * class Input {
 * public:
 *     bool done(); 
 *         // Returns true if the iteration has elements or false.
 *     void next();
 *         // Move to the next element in the iteration
 *         // Runtime error if the iteration has no more elements
 *     T value();
 *        // Get the current element, Runtime error if
 *        // the iteration has no more elements
 * }
 */
class SortIntegersMapper: public Mapper {
public:
    void Map(int _, Input<vector<int>>* input) {
        // Write your code here
        // Please directly use func 'output' to output 
        // the results into output buffer.
        // void output(string &key, vector<int>& value);
        unordered_map<int, int> counting_sort;
        while (!input->done()) {
            vector<int> data = input->value();
            sort(data.begin(), data.end());
            string kKey = "ignore_key";
            output(kKey, data);
            input->next();
        }
    }
};

class SortIntegersReducer: public Reducer {
public:
    void Reduce(string &key, vector<vector<int>>& input) {
        vector<int> ret = mergeSortedArrays(input);
        string kKey = "ignore_key";
        output(kKey, ret);
    }
    
private:
    template<class T>
    vector<T> mergeSortedArrays(vector<vector<T>>& arrays) {
        struct Node {
            typename vector<T>::iterator current;
            typename vector<T>::const_iterator end;
            bool operator < (const Node& n) const {
                return *current > *n.current;
            }
        };
        priority_queue<Node> pq;
        for (vector<T>& array : arrays) {
            if (!array.empty()) {
                pq.push(Node{array.begin(), array.end()});
            }
        }
        
        vector<T> ret;
        while (!pq.empty()) {
            Node n = pq.top();
            pq.pop();
            ret.push_back(*n.current++);
            if (n.current != n.end) { pq.push(n); }
        }
        return ret;
    }
};
