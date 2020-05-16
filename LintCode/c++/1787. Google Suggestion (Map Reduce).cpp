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
 * Definition of Document:
 * class Document {
 * public:
 *     int count; // document count
 *     string word; // document content
 * }
 */
class GoogleSuggestionMapper: public Mapper {
public:
    void Map(Input<Document>* input) {
        while (!input->done()) {
            Document doc = input->value();
            auto p = make_pair(doc.word, doc.count);
            string key;
            for (char c : doc.word) {
                key += c;
                output(key, p);
            }
            input->next();
        }
    }
};

struct cmp {
    template<class T>
    bool operator()(const T& a, const T& b) {
        if(a.second == b.second) {
            return a.first < b.first;
        } else {
            return a.second > b.second;
        }
    }
};

class GoogleSuggestionReducer: public Reducer {
public:
    void Reduce(string &key, Input<pair<string, int>>* input) {
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        while (!input->done()) {
            pq.push(input->value());
            if (pq.size() > 10) {
                pq.pop();
            }
            input->next();
        }
        
        stack<pair<string, int>> s;
        while (!pq.empty()) {
            s.push(pq.top());
            pq.pop();
        }
        while (!s.empty()) {
            output(key, s.top());
            s.pop();
        }
    }
};
