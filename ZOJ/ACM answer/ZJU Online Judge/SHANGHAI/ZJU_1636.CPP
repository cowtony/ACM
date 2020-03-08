#include <stdio.h>
#include <string.h>

#define maxn 510

int n , m;
int s[maxn][maxn];

int main(){
	int T , i , j;
	int key , sum;
	int query , x1 , y1 , x2 , y2;

	scanf("%d" , &T);
	for(int caseno=1; caseno<=T; caseno++){
		scanf("%d %d" , &n , &m);
		memset(s , 0 , sizeof(s));
		for(i=1; i<=n; i++){
			sum = 0;
			for(j=1; j<=m; j++){
				scanf("%d" , &key);
				sum += key * key;
				s[i][j] = sum + s[i-1][j];
			}
		}
	
		printf("Case %d:\n" , caseno);
		scanf("%d" , &query);
		while(query--){
			scanf("%d %d %d %d" , &x1 , &y1 , &x2 , &y2);
			printf("%d\n" , s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]);
		}
	}	

	return 0;
}
