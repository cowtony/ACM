#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int m , n;
int ret;
bool G[21][21];
int d[21];

string buf;

bool check(){
	int i , j , k;
	for(i=k=0; i<n; i++){
		k += d[i] % 2;
	}
	if(k > 2) return 0;
	if(k == 2 && (d[0] % 2 == 0 || d[m] % 2 ==0 || m == 0)) return 0;
	for(i=0; i<n; i++) G[i][i] = 1;
	for(k=0; k<n; k++)
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)				
				G[i][j] = G[i][j] || (G[i][k] && G[k][j]);	
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++){
			if(d[i] == 0 || d[j] == 0) continue;
			if(!G[i][j]) return 0;
		}
	if (!G[0][m]) return 0;
	return 1;
}

int main(){
	int i , k;
	while(cin >> buf , buf != "ENDOFINPUT"){
		cin >> m >> n;
		cin.get();

		memset(G , 0 , sizeof(G));
		memset(d , 0 , sizeof(d));
		ret = 0;
		for(i=0; i<n; i++){
			getline(cin , buf);
			istringstream strin(buf);
			while(strin >> k){
				d[i]++; d[k]++; ret++;
				G[i][k] = G[k][i] = 1;
			}
		}		

		if (check()) cout << "YES " << ret << endl;
		else cout << "NO" << endl;
		cin >> buf;
	}

	return 0;
}
