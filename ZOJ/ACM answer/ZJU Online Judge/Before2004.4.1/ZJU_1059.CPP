//判断某一条边是否是确定的充要条件是：删除该边以后剩下的图中不存在一个完美匹配

#include <stdio.h>
#include <string.h>
#define MAXN 25

int N , M;
char id[MAXN][81], name[MAXN][81], str[81];
int p[MAXN];
bool App[MAXN];
bool G[MAXN][MAXN];

int cx[MAXN] , cy[MAXN] , cx0[MAXN] , cy0[MAXN];
bool visited[MAXN];

int find_id(){
	for(int i=0; i<N; i++)
		if ( strcmp(str , id[i]) == 0 ) return i;
}

int find_name(){
	for(int i=0; i<M; i++)
		if ( strcmp(str , name[i]) == 0 ) return i;
	strcpy( name[M ++] , str ); 
	return M - 1;
}

int path( int v ){
	for(int u = 0; u < N; u++)
		if (!visited[u] && G[v][u]){
			visited[u] = true;
			if (cy[u] == -1 || path(cy[u]) ){
				cx[v] = u; cy[u] = v; return 1;
			}
		}
	return 0;
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	
	int CaseNo;
	int i,j,k;
	char ch;

	scanf("%d" , &CaseNo);	
	while(CaseNo --){
		scanf("%d" , &N);
		for(i=0; i<N; i++)
			scanf("%s" , id[i]);
		M = 0;
		memset(App , 0 , sizeof(App));
		memset(G , 1 , sizeof(G));
		while( true ){
			scanf("%1s" , &ch);			
			if (ch == 'Q'){
				break;
			};
			scanf("%s" , str);
			if (ch == 'E'){
				k = find_name();
				App[k] = true;
			}
			else if (ch == 'L'){
				k = find_name();
				App[k] = false;
			}
			else {
				k = find_id();
				for(i = 0; i< N; i++)
					if (! App[i]) G[i][k] = false;
			}
		}

		memset(cx , 255 ,sizeof(cx));
		memset(cy , 255 ,sizeof(cy));
		for(i = 0; i < N; i++)
			if (cx[i] == -1){
				memset(visited , 0 , sizeof(visited));
				path(i);
			}

        for( i = 0; i<N; i++)
			p[i] = i;
		for( i = 0; i<N; i++)
			for(j = i+1; j<N; j++)
				if (strcmp(name[p[j]] , name[p[i]]) < 0 ){
					k = p[i]; p[i] = p[j]; p[j] = k;
				}

		memcpy(cx0 , cx , sizeof(cx));
		memcpy(cy0 , cy , sizeof(cy));

		for( i = 0; i<N; i++){			
			memcpy(cx , cx0 , sizeof(cx0));
			memcpy(cy , cy0 , sizeof(cy0));

			G[ p[i] ][ cx0[p[i]] ] = false;
			cx[p[i]] = cy[ cx0[p[i]] ] = -1;
			printf("%s:",name[p[i]]);
			memset(visited , 0 , sizeof(visited));
			if (path(p[i])){
				printf("???\n");
			}
			else printf("%s\n",id[ cx0[p[i]] ]);

			G[ p[i] ][ cx0[p[i]] ] = true;
		}

		if (CaseNo) printf("\n");
	}

	return 0;
}