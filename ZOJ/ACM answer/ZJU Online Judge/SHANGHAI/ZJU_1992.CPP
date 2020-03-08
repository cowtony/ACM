#include <stdio.h>
#include <string.h>

#define maxn 210

int n , m;
int g[maxn][maxn];
int cap[maxn] , deg[maxn];
int prev[maxn] , Q[maxn] , visited[maxn];

void init(){
	scanf("%d %d" , &n , &m);
	int a , b , d , i;

	memset(g , 0 , sizeof(g));
	memset(cap , 0 , sizeof(cap));
	memset(deg , 0 , sizeof(deg));

	for(i=0; i<m; i++){
		scanf("%d %d %d" , &a , &b , &d);
		if(a == b) continue;
		--a , --b;
		if(d == 0){
			g[a][b]++;
		}
		++deg[a] , ++deg[b];
		++cap[a] , --cap[b];
	}
}

int path(int u){
	int i , k;
	int head , tail;
	head = tail = 0; Q[tail] = u;
	memset(visited , 0 , sizeof(visited)); visited[u] = 1;

	while(head <= tail){
		k = Q[head++];
		for(i=0; i<n; i++)
			if(!visited[i] && g[k][i]){
				visited[i] = 1; prev[i] = k;
				if(cap[i] < 0) return i;
				Q[++tail] = i;
			}
	}

	return -1;
}

void modify(int ed , int st){
	int j , i;
	j = ed;
	while(j != st){
		i = prev[j];
		g[i][j]--; g[j][i]++;
		j = i;
	}
	cap[ed] += 2;
	cap[st] -= 2;
}

bool solve(){
	int i , k;
	for(i=0; i<n; i++)
		if(deg[i] % 2) return 0;

	for(i=0; i<n; i++){
		while(cap[i] > 0){
			k = path(i);
			if(k < 0) return 0;
			modify(k , i);
		}
	}
	
	return 1;
}

int main(){
//	freopen("g.in" , "r" , stdin);
	int T;
	scanf("%d" , &T);
	while(T--){
		init();
		if(solve()) puts("possible");
		else puts("impossible");
	}

	return 0;
}
