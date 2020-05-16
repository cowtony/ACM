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
 *     int id; // document id
 *     string content; // document content
 * }
 */
class InvertedIndexMapper: public Mapper {
public:
    void Map(Input<Document>* input) {
        while (!input->done()) {
            string doc = input->value().content;
            while (!doc.empty()) {
                while (doc.front() == ' ') {
                    doc = doc.substr(1);
                }
                int len = doc.find(' ');
                if (len == string::npos) {
                    len = doc.length();
                }
                string word = doc.substr(0, len);
                output(word, input->value().id);
                
                doc = doc.substr(len);
                while (doc.front() == ' ') {
                    doc = doc.substr(1);
                }
            }
            input->next();
        }
    }
};


class InvertedIndexReducer: public Reducer {
public:
    void Reduce(string &key, Input<int>* input) {
        set<int> res;
        while (!input->done()) {
            res.insert(input->value());
            input->next();
        }
        output(key, vector<int>{res.begin(), res.end()});
    }
};
