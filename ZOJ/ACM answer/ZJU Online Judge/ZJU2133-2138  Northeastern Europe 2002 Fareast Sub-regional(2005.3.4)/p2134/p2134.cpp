#include <cstdio>
#include <cstring>

const int maxn = 30;

int n;
int C[maxn][maxn];
int Sum[maxn] , pL[maxn];

void init()
{
	scanf("%d" ,&n);

	int i , j;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d" , &C[i][j]);
}

int ret;

void search(int p , int gain)
{
	if(p == n)
	{
		if(gain > ret) ret = gain;
		return;
	}
	int i;
	for(i=p+1; i<n; i++)
		pL[i] += C[p][i];
	search(p + 1 , gain + Sum[p]);
	for(i=p+1; i<n; i++)
		pL[i] -= C[p][i];
	
	for(i=p+1; i<n; i++)
		Sum[i] += C[p][i];
	search(p + 1 , gain + pL[p]);
	for(i=p+1; i<n; i++)
		Sum[i] -= C[p][i];
}

void solve()
{
	ret = 0;

	memset(pL , 0 , sizeof(pL));

	n--;
	for(int i=0; i<n; i++)
		Sum[i] = C[i][n];

	search(0 , 0);

	printf("%d\n" , ret);
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