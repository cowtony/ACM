#include <stdio.h>
#include <string.h>
#include <math.h>

int n , m;
struct point {
	int x , y;
} list[51] , spot[1001];

bool g[51][51] , app[51][51];
double dist[51][51] , f[51][51];

void init(){
	scanf("%d %d" , &n , &m);
	int i;
	for(i=0; i<n; i++) scanf("%d %d" , &list[i].x , &list[i].y);
	for(i=0; i<m; i++) scanf("%d %d" , &spot[i].x , &spot[i].y);
}

inline int multiply(point& p1 , point& p2 , point& p0){
	return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x); 
}

inline double distance(point& a , point& b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

inline int next(int p){
	return (p + 1) % n;
}

point p0 , p1;

double dp(int p , int r){
	if(app[p][r]) return f[p][r];	
	if(g[r][p] && multiply( p1 , list[p] , p0) != 0) return dist[p][r];
	app[p][r] = 1;
	f[p][r] = 1e20;
	double tmp;
	for(int i=next(p); i!=r; i=next(i)){
		if(g[i][p]){
			tmp = dist[i][p] + dp(i , r);
			if(tmp < f[p][r]) f[p][r] = tmp;
		}
		else break;
	}
	return f[p][r];
}

void solve(){
	int i , j , k;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++){
			dist[i][j] = distance(list[i] , list[j]);
			g[i][j] = 0;
			if(i == j) continue;
			for(k=0; k<m; k++){
				if(multiply(list[j] , spot[k] , list[i]) <= 0) break;
			}
			if(k == m) g[i][j] = 1;
		}

	double ret = 1e20 , tmp;
	memset(app , 0 , sizeof(app));

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(g[i][j]){
				p0 = list[i]; p1 = list[j];
				tmp = dist[i][j] + dp(i , j);
				if(tmp < ret){
					ret = tmp;
				}
			}

	printf("%.2lf\n" , ret);
}

int main(){	
	freopen("in.txt" , "r" , stdin);
	int T;
	scanf("%d" , &T);
	while(T--){
		init();
		solve();

		if(T) putchar('\n');
	}
	
	
	return 0;
}
