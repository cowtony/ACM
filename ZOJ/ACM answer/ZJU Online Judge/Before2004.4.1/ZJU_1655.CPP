#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int n , m;
int List[101];
double G[101][101];
int main(){
	//freopen("in.txt","r",stdin);
	int i , j , k , a , b;
	double rate;
	while(cin >> n >> m){
		for(i=1; i<n; i++)
			cin >> List[i];
		memset(G , 0 , sizeof(G));
		for(i=1; i<=m; i++){
			cin >> a >> b >> rate;
			
			rate = 1 - rate;
			if (rate > G[a][b]){
				G[a][b] =G[b][a] = rate;
			}
		}
		for(k=1; k<=n; k++)
			for(i=1; i<=n; i++)
				for(j=1; j<=n; j++)
					if(G[i][j] < G[i][k] * G[k][j]){
						G[i][j] = G[i][k] * G[k][j];
					}
		double tot = 0;
		for(i=1; i<n; i++)
			tot += List[i] * G[i][n];
		printf("%.2lf\n" , tot);
	}
	return 0;
}