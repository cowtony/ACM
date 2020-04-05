class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        multimap<int, char> m;
        m.emplace(a, 'a');
        m.emplace(b, 'b');
        m.emplace(c, 'c');
        
        auto it = m.begin();
        c = it->first;
        char C = it->second;
        it++;
        b = it->first;
        char B = it->second;
        it++;
        a = it->first;
        char A = it->second;
        
        a = min(a, (b + c + 1) * 2);
        
        string s(a, A);
        cout << s << endl;
        int i;
        for (i = 2; i <= s.length(); i += 2) {
            if (b > 0) {
                s.insert(i, string(1, B));
                i += 1;
                b -= 1;
            } else {
                break;
            }
        }
        cout << i << " " << s << endl;
        if (b > 0) {
            for (i = 3; i <= s.length(); i += 3) {
                if (b > 0) {
                    s.insert(i, string(1, B));
                    i += 1;
                    b -= 1;
                } else {
                    break;
                }
            }
        }
        cout << i << " " << s << endl;

        for (; i <= s.length(); i += 2) {
            if (c > 0) {
                s.insert(i, string(1, C));
                i += 1;
                c -= 1;
            } else {
                break;
            }
        }
        cout << i << " " << s << endl;
        if (c > 0) {
            for (i = 0; i <= s.length(); i += 1) {
                if (c > 0) {
                    s.insert(i, string(1, C));
                    i += 1;
                    c -= 1;
                } else {
                    break;
                }
            }
        }

        cout << i << " " << s << endl;
        return s;
    }
};
