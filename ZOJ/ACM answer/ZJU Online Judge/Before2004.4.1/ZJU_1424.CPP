#include <stdio.h>
#include <string.h>
#define MAXN 30

int T,n;
struct rec{
	int x1,y1,x2,y2,c;
};
rec List[ MAXN ];
int Best;

int Degree[ MAXN ];
bool G[ MAXN ][ MAXN ];
int Color[ MAXN ];

void Search( int N , int c){
	if ( N == 0){		
		if (c - 1 < Best) Best = c - 1;
		return;
	}

	int p,i,j,ret;
	bool modify;
	for(p = 1; p <= 20; p++){
		ret = 0;
		modify = 1;
		while(modify){
			modify = 0;
			for(i = 0; i<n; i++)
				if(Degree[i] == 0 && Color[i] == 0 && List[i].c == p){
					modify = 1;
					Color[i] = c;
					ret ++ ;
					for(j = 0; j < n; j++)
						if (G[i][j]){
							Degree[j] --;
						}
				}
		}

		if (ret == 0) continue;

		Search ( N - ret , c + 1 );
		for(i = 0; i < n; i++)
			if (Color[i] == c){
				Color[i] = 0;
				for(j = 0; j < n; j++)
					if (G[i][j]){
						Degree[j] ++;
					}
			}
	}
}

int main(){	
	int i,j;

	scanf("%d" , &T);
	while( T -- ){
		scanf("%d" , &n);
		for (i = 0; i < n; i++){
			scanf("%d %d %d %d %d" , &List[i].x1 , &List[i].y1 , &List[i].x2 , &List[i].y2 , &List[i].c);
		}

		//Build Graph... G[i][j] = 1  : i should be painted before j
		memset( G , 0 , sizeof(G));
		memset( Degree , 0 ,sizeof(Degree));
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (List[i].x2 == List[j].x1 && List[i].y1 < List[j].y2 && List[i].y2 > List[j].y1){
					G[i][j] = 1;
					Degree[ j ] ++;
				}
		
		Best = n;

		memset(Color , 0 , sizeof(Color));
		Search( n , 1 );

		printf("%d\n" , Best);
	}

	return 0;
}