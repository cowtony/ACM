#include <stdio.h>
#include <string.h>

int n;
int cost[1010];
int g[1010][1010];
int low[1010];

void solve(){
	int cost = 0;
	int i , j , min , k;

	for(i=0; i<n; i++)
		low[i] = g[0][i];
	low[0] = -1;
	for(i=1; i<n; i++){
		min = 10000000;
		for(j=0; j<n; j++)
			if(low[j]>0 && low[j] < min){
				min = low[j];
				k = j;
			}
		cost += min;
		low[k] = -1;
		for(j=0; j<n; j++)
			if(g[k][j] < low[j]) low[j] = g[k][j];
	}

	printf("%d\n" , cost);
}

int main(){
	int t , i , j;
	scanf("%d" , &t);
	while(t--){
		scanf("%d" , &n);
		for(i=0; i<n; i++)
			scanf("%d" , cost + i);
		for(i=0; i<n; i++)
			for(j=0; j<n; j++){
				scanf("%d" , &g[i][j]);
				g[i][j] += cost[i] + cost[j];
			}
			
		solve();

	}
	
	return 0;
}
