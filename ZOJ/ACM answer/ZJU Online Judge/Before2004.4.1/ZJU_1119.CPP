#include <stdio.h>
#include <string.h>
#define MAXN 1001

bool G[MAXN][MAXN];
struct nodeDat{	
	int mark,low,sons,pre,link;
};
nodeDat List[MAXN];
int time = 0;
int N;


void DFS( int u ){
	++time;
	List[u].mark = List[u].low = time;
	List[u].sons = 0;
	for(int v = 1; v <= N; v++)
		if (G[u][v]){
			if (!List[v].mark){
				G[v][u] = 0; ++List[u].sons; ++List[u].link;
				List[v].pre = u;
				DFS(v);
				if (List[v].low < List[u].mark) --List[u].link; 
				G[v][u] = 1;
				if( List[u].low > List[v].low ) List[u].low = List[v].low;
			}			
			else if( List[u].low > List[v].mark) List[u].low = List[v].mark;
		}	
}

void Solve(){
	int  i , j;
	memset(List , 0 ,sizeof(List));
	int C = 0; 
	time = 0;
	for(i = 1; i <= N; i++)
		if(! List[i].mark ){
			DFS(i);			
		}
	for(i = 1; i <= N; i++)
		if (List[i].pre == 0){
			if (List[i].sons > 1){
				printf("  SPF node %d leaves %d subnets\n" , i , List[i].sons); ++C;
			}
		}
		else{
			for(j = 1; j <= N; j++)
				if (List[j].pre == i && List[j].low >= List[i].mark){
					printf("  SPF node %d leaves %d subnets\n" , i , List[i].link + 1); ++C;					
					break;
				}
		}
	
	if (C == 0){
		printf("  No SPF nodes\n");
	}
}

int main(){
	//freopen("in.txt","r",stdin);

	int CaseNo = 0;
	int a,b;
	while(scanf("%d" , &a) , a){
		N = a;
		memset( G , 0 ,sizeof(G));
		scanf("%d" , &b);
		if (a > N) N = a;

		G[a][b] = G[b][a] = 1;
		while(scanf("%d" , &a) , a){
			scanf("%d" , &b);
			G[a][b] = G[b][a] = 1;
			if (a > N) N = a;
			if (b > N) N = b;
		}

		if (CaseNo) putchar('\n');
		printf("Network #%d\n" , ++CaseNo);
		Solve();
	}
	
	return 0;
}
