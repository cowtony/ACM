class FileSystem {
public:
    FileSystem() {
        
    }
    
    vector<string> ls(string path) {
        vector<string> path_list = split(path, "/");
        Folder* folder = &root;
        for (int i = 0; i < path_list.size(); i++) {
            if (i == path_list.size() - 1 and folder->files.find(path_list[i]) != folder->files.end()) {
                return {path_list.back()};
            }
            folder = folder->folders[path_list[i]];
        }
        
        set<string> res;
        for (auto p : folder->folders) {
            res.insert(p.first);
        }
        for (auto p : folder->files) {
            res.insert(p.first);
        }
        return {res.begin(), res.end()};
    }
    
    void mkdir(string path) {
        Folder* folder = &root;
        for (string name : split(path, "/")) {
            if (folder->folders.find(name) == folder->folders.end()) {
                folder->folders[name] = new Folder;
            }
            folder = folder->folders[name];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> path_list = split(filePath, "/");
        Folder* folder = &root;
        for (int i = 0; i < int(path_list.size()) - 1; i++) {
            if (folder->folders.find(path_list[i]) == folder->folders.end()) {
                folder->folders[path_list[i]] = new Folder;
            }
            folder = folder->folders[path_list[i]];
        }
        folder->files[path_list.back()] += content;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> path_list = split(filePath, "/");
        Folder* folder = &root;
        for (int i = 0; i < int(path_list.size()) - 1; i++) {
            folder = folder->folders[path_list[i]];
        }
        return folder->files[path_list.back()];
    }
    
private:
    struct Folder {
        unordered_map<string, Folder*> folders;
        unordered_map<string, string> files;
    } root;
    
    vector<string> split(string s, string delimiter) {
        vector<string> res;
        size_t p = 0;
        while (p <= s.length()) {
            size_t pos = s.find(delimiter, p);
            if (pos == string::npos) {
                pos = s.length();
            }
            if (!s.substr(p, pos - p).empty()) {
                res.emplace_back(s.substr(p, pos - p));
            }
            p = pos + delimiter.length();
        }
        return res;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
