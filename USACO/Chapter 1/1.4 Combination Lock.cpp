/*
ID:cowtony1
PROG:combo
LANG:C++
*/
#include <bits/stdc++.h>
using namespace std;

int N;
unordered_set<int> result;

int hashCombo(const vector<int>& combinition) {
	return (combinition[0] + N - 1) % N * N * N + 
		   (combinition[1] + N - 1) % N * N + 
		   (combinition[2] + N - 1) % N;
}

void dfs(vector<int>& combinition, int idx) {
	if (idx == combinition.size()) {
		result.insert(hashCombo(combinition));
		return;
	}

	for (int i = 0; i <= 4; ++i) {
		combinition[idx] += i;
		dfs(combinition, idx + 1);
		combinition[idx] -= i;
	}
}

int main() {
	ifstream fin("combo.in");
    ofstream fout("combo.out");
	
	fin >> N;
	vector<int> combinitions(3);
	for (int i = 0; i < 3; i++) {
		fin >> combinitions[i];
		combinitions[i] -= 2;
	}
	dfs(combinitions, 0);

	for (int i = 0; i < 3; i++) {
		fin >> combinitions[i];
		combinitions[i] -= 2;
	}
	dfs(combinitions, 0);

    fout << result.size() << endl;
	cout << result.size() << endl;
	return 0;
}