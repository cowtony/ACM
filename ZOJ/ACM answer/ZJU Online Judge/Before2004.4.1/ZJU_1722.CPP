#include <stdio.h>
#include <string.h>
char name[100][11];
int B[100] , D[100] , S[100];
int L[100][10], U[100][10];

int N , Q , k;
char buf[11];
int x[10];


int main(){
	//freopen("in.txt" , "r" , stdin);
	int i , j , ret , w;
	while(scanf("%d %d" , &N , &Q) != EOF){
		for(i = 0; i < N; i++){
			scanf("%s %d %d %d" , name[i] , &B[i] , &S[i], &D[i]);
			for(j=0; j<D[i]; j++)
				scanf("%d %d" , &L[i][j] , &U[i][j]);
		}
		for(i = 0; i < Q; i++){
			scanf("%s" , buf);
			for(k = 0; k < N; k++)
				if(strcmp(buf , name[k]) == 0) break;
			for(j = 0; j < D[k]; j++)
				scanf("%d" , &x[j]);
			w = S[k]; ret = B[k];
			for(j = D[k] - 1; j >= 0; j --){
				ret += w * (x[j] - L[k][j]) ;
				w *= (U[k][j] - L[k][j] + 1);
			}
			printf("%s[" , buf);
			for(j = 0; j < D[k] - 1; j++)
				printf("%d, " , x[j]);
			printf("%d] = %d\n" , x[D[k]-1] , ret);
		}
	}	
	return 0;
}
