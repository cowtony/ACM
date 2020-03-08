#include <stdio.h>
#include <string.h>

int n;
int g[502][502];

inline int v(int i , int j){
	if(i==1 || i==n || j==1 || j==n) return g[i][j];
	return ((g[i-1][j-1] + g[i-1][j+1] + g[i+1][j-1] + g[i+1][j+1])
		   +(g[i-1][j] + g[i][j-1] + g[i+1][j] + g[i][j+1]) * 2
		   +g[i][j] * 4) >> 4;
}

int main(){
	int i , j;
	int caseno = 0;
	while(scanf("%d" , &n) , n){
		memset(g , 0 , sizeof(g));
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				scanf("%d" , &g[i][j]);
		printf("Case %d:\n" , ++caseno);
		for(i=1; i<=n; i++){
			for(j=1; j<n; j++)
				printf("%d " , v(i,j));
			printf("%d\n" , v(i,j));
		}
				
	}
	
	return 0;
}
