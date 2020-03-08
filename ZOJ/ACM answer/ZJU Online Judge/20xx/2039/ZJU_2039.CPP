#include <stdio.h>
#include <string.h>
#include <math.h>

int n , m;
int g[101][101];
struct point{
	int x , y;
} path[101] , inst[101];
int cx[101] , cy[101];
bool visited[101];

void init(){
	int i;

	scanf("%d %d" , &n , &m);
	n--;
	for(i=0; i<=n; i++)
		scanf("%d %d" , &path[i].x , &path[i].y);
	for(i=0; i<m; i++)
		scanf("%d %d" , &inst[i].x , &inst[i].y);
}

double dist(const point& a , const point& b){
	return sqrt((double)(a.x - b.x) * (a.x - b.x) + (double)(a.y - b.y) * (a.y - b.y));
}

int gen_path(int u){
	for(int i=0; i<m; i++)
		if(!visited[i] && g[u][i]){
			visited[i] = 1;
			if(cy[i] < 0 || gen_path(cy[i])){
				cy[i] = u; cx[u] = i;
				return 1;
			}
		}
	return 0;
}

void solve(){
	int i , j;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			g[i][j] = (dist(path[i] , inst[j]) + dist(inst[j] , path[i+1]) <= 2 * dist(path[i] , path[i + 1]));
			
	memset(cx , 0xff , sizeof(cx));
	memset(cy , 0xff , sizeof(cy));

	int ret = 0;
	for(i=0; i<n; i++)
		if(cx[i] < 0){
			memset(visited , 0 , sizeof(visited));
			ret += gen_path(i);
		}
	
	printf("%d\n" , ret + n + 1);
	for(i=0; i<n; i++){
		printf("%d %d " , path[i].x , path[i].y);
		if(cx[i] >= 0){
			printf("%d %d " , inst[cx[i]].x , inst[cx[i]].y);
		}
	}
	printf("%d %d\n" , path[n].x , path[n].y);
}

int main(){
	int T;
	scanf("%d" , &T);

	while(T--)
	{		
		init();
		solve();
		if(T) putchar('\n');
	}
	
	return 0;
}
