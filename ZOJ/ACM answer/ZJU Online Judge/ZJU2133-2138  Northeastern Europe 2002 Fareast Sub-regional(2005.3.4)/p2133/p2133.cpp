#include <cstdio>
#include <cstring>

int n;
char g[60][30];
int A[30][30];
int deg[30];
bool app[30];

void init()
{
	scanf("%d" , &n);
	for(int i=0; i<n; i++)
		scanf("%s" , g[i]);
}

void solve()
{
	memset(A , 0 , sizeof(A));
	memset(deg , 0 , sizeof(deg));
	memset(app , 0 , sizeof(app));

	int i , j , k;

	for(i=0; i<n; i++)
		for(j=0; j<20; j++)
			if(g[i][j] != '.') app[g[i][j] - 'A'] = 1;

	for(i=0; i<n-1; i++)
	{
		for(j=0; j<20; j++)
		{
			if(g[i][j] != '.' && g[i+1][j] != '.' && g[i][j] != g[i+1][j])
			{
				A[g[i+1][j]-'A'][g[i][j]-'A']++;
				deg[g[i][j]-'A']++;
			}
		}
	}

	for(i=0; i<30; i++)
		if(!app[i]) deg[i] = -1;

	/// generate the sequence
	while(1)
	{
		for(j=0; j<30; j++)
			if(deg[j] == 0) break;
		if(j == 30) break;
		putchar(j + 'A');
		deg[j] = -1;
		for(k=0; k<30; k++)
			if(A[j][k]) deg[k] -= A[j][k];
	}
	putchar('\n');
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

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