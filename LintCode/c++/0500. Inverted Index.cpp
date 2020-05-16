/**
 * Definition of Document:
 * class Document {
 * public:
 *     int id;
 *     string content;
 * }
 */
class Solution {
public:
    /**
     * @param docs a list of documents
     * @return an inverted index
     */
    map<string, vector<int>> invertedIndex(vector<Document>& docs) {
        map<string, set<int>> counting;
        for (const Document& doc : docs) {
            for (string word : split(doc.content, " ")) {
                if (!word.empty()) {
                    counting[word].insert(doc.id);
                }
            }
        }
        map<string, vector<int>> ret;
        for (auto p : counting) {
            ret[p.first] = {p.second.begin(), p.second.end()};
        }
        return ret;
    }
};
