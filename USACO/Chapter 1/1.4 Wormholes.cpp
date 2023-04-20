/*
ID:cowtony1
PROG:wormhole
LANG:C++
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> next_on_right;
bool hasCycle(const vector<int>& partners) {
    for (int i = 0; i < partners.size(); i++) {
        int j = i;
        do {
            j = partners[j];
            j = next_on_right[j];
        } while (j != -1 && j != i);
        if (j == i) {
            return true;
        }
    }
    return false;
}

int result = 0;
void dfs(vector<int>& partners, int i) {
    while (i < partners.size() && partners[i] != -1) {
        ++i;
    }
    if (i == partners.size()) {
        if (hasCycle(partners)) {
            ++result;
        }
        return;
    }

    for (int j = i + 1; j < partners.size(); ++j) {
        if (partners[j] == -1) {
            partners[i] = j;
            partners[j] = i;
            dfs(partners, i + 1);
            partners[i] = partners[j] = -1;
        }
    }
}

int main() {
	ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");

    int N;
    fin >> N;
    vector<pair<int, int>> wormholes(N);
    for (int i = 0; i < N; ++i) {
        fin >> wormholes[i].first >> wormholes[i].second;
    }

    next_on_right = vector<int>(N, -1);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (wormholes[i].second == wormholes[j].second && wormholes[i].first < wormholes[j].first) {  // in same y-axis
                if (next_on_right[i] == -1 || wormholes[j].first < wormholes[next_on_right[i]].first) {
                    next_on_right[i] = j;
                }
            }
        }
    }

    vector<int> partners(N, -1);
    dfs(partners, 0);

    fout << result << endl;
    cout << result << endl;

    return 0;
}