/* Definition of BaseGFSClient
 * class BaseGFSClient {
 * private: map<string, string> chunk_list;
 * public:
 *     string readChunk(string& filename, int chunkIndex) {
 *         // Read a chunk from GFS
 *     }
 *     void writeChunk(string& filename, int chunkIndex,
 *                     string& content) {
 *         // Write a chunk to GFS     
 *     }
 *  };
 */


class GFSClient : public BaseGFSClient {
public:
    /*
    * @param chunkSize: An integer
    */GFSClient(int chunkSize) {
        chunk_size = chunkSize;
    }

    /*
     * @param filename: a file name
     * @return: conetent of the file given from GFS
     */
    string read(string &filename) {
        if (headers.find(filename) == headers.end()) {
            return string();
        }
        string ret;
        for (int id : headers.at(filename)) {
            ret += client.readChunk(filename, id);
        }
        return ret;
    }

    /*
     * @param filename: a file name
     * @param content: a string
     * @return: nothing
     */
    void write(string &filename, string &content) {
        headers[filename].clear();
        for (int i = 0; i < content.size(); i += chunk_size) {
            string s = content.substr(i, chunk_size);
            client.writeChunk(filename, auto_inc, s);
            headers[filename].push_back(auto_inc++);
        }
    }
    
private:
    int chunk_size;
    int auto_inc = 0;
    BaseGFSClient client;
    unordered_map<string, vector<int>> headers; // <file_name, id_list>
};
