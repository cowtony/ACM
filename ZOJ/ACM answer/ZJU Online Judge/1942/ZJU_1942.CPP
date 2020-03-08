#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int n , m;
struct point
{
	double x , y;
} list[201];
struct edgetype
{
	int a , b;
	double d;
} edge[201 * 100];
int parent[201];

void init()
{
	for(int i=0; i<n; i++)
		scanf("%lf%lf" , &list[i].x , &list[i].y);
}

inline double dist(const point& a , const point& b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

inline int double_cmp(const double&a , const double& b)
{
	if(a == b) return 0;
	if(a < b) return -1;
	return 1;
}

int cmp(const void* a , const void* b)
{
	return double_cmp(((edgetype*)a)-> d , ((edgetype*)b)-> d);
}

int find(int u)
{
	if(parent[u] != u) parent[u] = find(parent[u]);
	return parent[u];
}

void solve()
{
	int i , j;
	m = 0;
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
		{
			edge[m].a = i;
			edge[m].b = j;
			edge[m].d = dist(list[i] , list[j]);
			m++;
		}
	qsort((void*)edge , m , sizeof(edgetype) , cmp);
	for(i=0; i<n; i++)
	{
		parent[i] = i;
	}
	for(i=0; i<m; i++)
	{
		parent[find(edge[i].a)] = find(edge[i].b);
		if(find(0) == find(1))
		{
			printf("Frog Distance = %.3lf\n" , edge[i].d);
			break;
		}
	}
}

int main()
{
	freopen("in.txt" , "r" , stdin);
	int t = 0;

	while(1)
	{
		scanf("%d" , &n);
		if(!n) break;

		printf("Scenario #%d\n" , ++t);
		init();
		solve();
		putchar('\n');
	}

	return 0;
}