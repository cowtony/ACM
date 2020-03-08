#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

int n;
struct point{
	int x , y;
} list[101];

struct person_info{
	int c , w , s;
} pl[101];

double g[101][101];
double f[1001][101];
int left , right;

void init(){
	int i;
	scanf("%d %d" , &left , &i); 
	for(i=0; i<n; i++)
		scanf("%d %d" , &list[i].x , &list[i].y);
	scanf("%d %d" , &right , &i);
	for(i=0; i<n; i++)
		scanf("%d %d %d" , &pl[i].c , &pl[i].w , &pl[i].s);
}

inline int max(int a , int b){
	return a > b ? a : b;
}

inline int min(int a , int b){
	return a < b ? a : b;
}

inline int mul(const point& p1 , const point& p2 , const point& p0){
	return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}

void prepare(){
	int i , j , k , p , r;
	
	point t;  t.y = 0;
	
	k = 0;
	for(i=left; i<=right; i++){
		while(k < n && list[k].x < i) k++;
		t.x = i;
		for(j=0; j<k; j++){
			f[i][j] = sqrt(list[j].y * list[j].y + (i - list[j].x) * (i - list[j].x));
			for(p=j+1; p<k; p++){
				if(mul(list[p] , list[j] , t) < 0){
					f[i][j] = -1; break;
				}
			}
		}
		for(j=k; j<n; j++){
			f[i][j] = sqrt(list[j].y * list[j].y + (i - list[j].x) * (i - list[j].x));
			for(p=k; p<j; p++){				
				if(mul(list[p] , list[j] , t) > 0){
					f[i][j] = -1; break;
				}
			}
		}
	}

	double tmp;
	
	for(i=0; i<n; i++)
		for(j=0; j<n; j++){
			g[i][j] = 1e20;
			p = min(pl[i].s , list[j].x);
			r = max(pl[i].s , list[j].x);
			for(k=p; k<=r; k++)
				if(f[k][j] >= 0){
					tmp = fabs(k - 	pl[i].s) / double(pl[i].w) + f[k][j] / pl[i].c;
					if(tmp < g[i][j]) g[i][j] = tmp;
				}
		}
}


double p , r , m;
int cx[101] , cy[101];
bool mark[101];

bool path(int u){
	for(int i=0; i<n; i++)
		if(g[u][i] <= m && !mark[i]){
			mark[i] = 1;
			if(cy[i] < 0 || path(cy[i])){
				cx[u] = i; cy[i] = u;
				return 1;
			}
		}
	return 0;
}

void solve(){
	p = 0; r = 1601.0;
	int i;
	int ret = 0;

	memset(cx , 0xff , sizeof(cx));
	memset(cy , 0xff , sizeof(cy));

	while( (r - p) >= 1e-3){
		m = (p + r) / 2.0;
		for(i=0; i<n; i++)
			if(cx[i] >= 0){
				if(g[i][cx[i]] > m) cy[cx[i]] = -1 , cx[i] = -1 , ret--;
			}

		for(i=0; i<n; i++)
			if(cx[i] < 0){
				memset(mark , 0 , sizeof(mark));
				if(path(i)) ret++;
				else break;
			}
		
		if(ret == n) r = m;
		else p = m;
	}

	printf("%.2lf\n" , (p + r) / 2);
}

int main(){
//	freopen("oopc1d/p5.in" , "r" , stdin);
//	freopen("in.txt" , "r" , stdin);

	while(scanf("%d" , &n) , n){
		init();
		prepare();
		solve();
	}
	
//	printf("Run Time	: %.2fs\n" , clock()/(float)CLK_TCK);

	return 0;
}
