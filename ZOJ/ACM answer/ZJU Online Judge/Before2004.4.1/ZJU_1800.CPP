#include <stdio.h>
#include <string.h>

int n , l , m , Len;
char List[601][12];
bool G[601][601];
int f[101][601];

int main(){
	//freopen("in.txt" , "r" , stdin);
	int i , j , k;
	while(scanf("%d%d%d" , &n , &l , &m) , n){
		for(i=0; i<m; i++)
			scanf("%s" , List[i]);
		Len = strlen(List[0]);		
		if(Len == 1){
			memset(G , 1 , sizeof(G));
		}
		else{
			for(i=0; i<m; i++)
				for(j=0; j<m; j++){					
					for(k=1; k<Len; k++)
						if(List[i][k] != List[j][k-1]) break;
					G[i][j] = k == Len;
				}
		}
		memset(f , 0 , sizeof(f));
		for(i=0; i<m; i++)
			f[Len][i] = 1;
		for(i=Len+1; i<=l; i++)
			for(j=0; j<m; j++)
				for(k=0; k<m; k++)
					if(G[k][j]) f[i][j] += f[i-1][k];
		int ret = 0;
		for(i=0; i<m; i++)
			ret += f[l][i];
		printf("%d\n" , ret);
	}

	return 0;
}