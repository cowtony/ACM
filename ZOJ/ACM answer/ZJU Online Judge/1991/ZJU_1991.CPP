#include <stdio.h>
#include <string.h>

int n , m;
bool g[201][201];
int pa[401] , pb[401] , k;
bool mx[201] , my[201];
int f[201][201];

void init()
{
	scanf("%d%d" , &n , &m);
	int a , b;
	memset(g , 0 , sizeof(g));
	for(int i=0; i<m; i++)
	{
		scanf("%d%d" , &a , &b);
		if(a > n || b > n) continue;
		a-- , b--;
		g[a][b] = 1;
	}
}

void dfs_x(int v);
void dfs_y(int v);

void dfs_x(int v)
{
	pa[k]++;
	mx[v] = 1;
	for(int i=0; i<n; i++)
		if(!my[i] && g[v][i]) dfs_y(i);
}

void dfs_y(int v)
{
	pb[k]++;
	my[v] = 1;
	for(int i=0; i<n; i++)
		if(!mx[i] && g[i][v]) dfs_x(i);
}

void predoing()
{
	k = 0;
	int i;

	memset(mx , 0 , sizeof(mx));
	memset(my , 0 , sizeof(my));
	memset(pa , 0 , sizeof(pa));
	memset(pb , 0 , sizeof(pb));

	for(i=0; i<n; i++)
		if(!mx[i])
		{
			dfs_x(i);
			k++;		
		}
	for(i=0; i<n; i++)
		if(!my[i])
		{
			pa[k] = 0;
			pb[k] = 1;
			k++;
		}	
}

void solve()
{
	int p , i , j;

	memset(f , 0 , sizeof(f));
	f[0][0] = 1;
	int sa , sb;
	sa = sb = 0;
	for(p=0; p<k; p++)
	{
		for(i=sa; i>=0; i--)
			for(j=sb; j>=0; j--)
				if(f[i][j]) f[i+pa[p]][j+pb[p]] = 1;
		sa += pa[p];
		sb += pb[p];
	}

	p = n/2;
	for(i=0; i<=p; i++)
	{
		if(f[p+i][p+i])
		{
			printf("%d\n" , p-i);
			break;
		}
		if(f[p-i][p-i])
		{
			printf("%d\n" , p-i);
			break;
		}		
	}	
}

int main()
{	
	int T;
	
	scanf("%d" , &T);

	while(T--)
	{
		init();
		predoing();
		solve();
	}
	
	return 0;
}
