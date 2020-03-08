#include <stdio.h>
#include <string.h>

int n , N;
int g[210][210];
bool exist[210][210];
char name[110][40];

int find_name(char* s){
	for(int i=1; i<=N; i++)
		if(strcmp(name[i] , s) == 0) return i;
	++N;
	strcpy(name[N] , s);
	return N;
}

void init(){
	scanf("%d" , &n);
	memset(exist , 0 ,sizeof(exist));
	memset(g , 0 , sizeof(g));

	int i , j , k , idx;
	char s[40];
	N = 0;

	for(i=1; i<=n; i++){
		scanf("%s" , s);
		idx = find_name(s);
		scanf("%d %d" , &g[0][idx] , &k);
		exist[0][idx] = 1;
		while(k--){
			scanf("%s" , s);
			j = find_name(s);
			scanf("%d" , &g[j][idx]);
			exist[j][idx] = 1;
		}
	}

	int m;
	scanf("%d" , &m);
	while(m--){
		scanf("%s" , s);
		g[0][find_name(s)] = 0;
	}
}

int cost;
int vcost;
bool valid[210] , inc[210];
int mark[210];
bool g1[210][210];
int path[210] , clen , edp[210];
int time;

void gen_g1(){
	int i , j , k , min;
	vcost = 0;
	memset(g1 , 0 , sizeof(g1));
	for(i=1; i<=n; i++){
		if(!valid[i]) continue;
		min = 10000000;
		for(j=0; j<=n; j++)
			if(valid[j] && exist[j][i] && g[j][i] < min){
				min = g[j][i];
				k = j;
			}
		vcost += min;
		g1[k][i] = 1;
	}
}

bool dfs(int u , int depth){
	mark[u] = time;
	path[depth] = u;
	for(int i=1; i<=n; i++)
		if(valid[i] && g1[u][i]){
			if(mark[i] == time){
				clen = depth;
				return 1;
			}
			if(mark[i]) continue;
			if(dfs(i , depth+1)) return 1;
		}
	return 0;
}

bool find_circle(){
	memset(mark , 0 , sizeof(mark));
	time = 0;
	for(int i=0; i<=n; i++)
		if(valid[i] && !mark[i]){
			++time;
			if(dfs(i , 0)) return 1;
		}
	return 0;
}

void modify_circle(){
	//ÊÕËõÈ¦

	int i , j;
	cost += g[path[clen]][path[0]]; edp[path[0]] = g[path[clen]][path[0]];
	for(i=0; i<clen; i++)
		cost += g[path[i]][path[i+1]] , edp[path[i+1]] = g[path[i]][path[i+1]];

	n++;
	int p;
	
	for(i=0; i<=clen; i++)
		valid[path[i]] = 0;

	for(i=0; i<n; i++)
		if(valid[i]){
			for(j=0; j<=clen; j++){
				if(exist[i][path[j]]){
					p = g[i][path[j]] - edp[path[j]];
					if(!exist[i][n] || p < g[i][n]){
						exist[i][n] = 1;
						g[i][n] = p;
					}
				}
				if(exist[path[j]][i]){
					p = g[path[j]][i];
					if(!exist[n][i] || p < g[n][i]){
						exist[n][i] = 1;
						g[n][i] = p;
					}
				}
			}
		}
}


void solve(){
	memset(valid , 1 ,sizeof(valid));
	cost = 0;

	while(1){
		gen_g1();
		if(find_circle()){
			modify_circle();
		}
		else{
			cost += vcost;
//			printf("%d\n" , cost);
			cost = cost / 5 + (cost % 5 > 0);
			printf("%d\n" , cost);
			break;
		}			
	}
}

int main(){
//	freopen("in.txt" , "r" , stdin);

	int T;
	scanf("%d" , &T);
	while(T--){
		init();
		solve();
	}
	
	return 0;
}
