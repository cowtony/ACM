#include <stdio.h>
#include <string.h>

int n;
int sum[1010];
int L , C;

struct dptype
{
	int x , c;
} f[1010];

void init()
{
	scanf("%d%d" , &L , &C);
	int key , i;
	sum[0] = 0;
	for(i=1; i<=n; i++)
	{
		scanf("%d" , &key);
		sum[i] = sum[i-1] + key;
	}
}

inline int cost (int v)
{
	v = L - v;
	if(v == 0) return 0;
	if(v <= 10) return -C;
	return (v-10)*(v-10);
}

void solve()
{
	f[0].x = f[0].c = 0;
	int i , j;

	for(i=1; i<=n; i++)
	{
		f[i].x = n*2;
		for(j=i-1; j>=0; j--)
			if(sum[i] - sum[j] <= L)
			{
				if(f[j].x+1 < f[i].x || (f[j].x + 1 == f[i].x && f[j].c + cost(sum[i] - sum[j]) < f[i].c))
				{
					f[i].x = f[j].x + 1;
					f[i].c = f[j].c + cost(sum[i] - sum[j]);
				}
			}
			else break;
	}
	printf("Minimum number of lectures: %d\nTotal dissatisfaction index: %d\n" , f[n].x , f[n].c);

}

int main(){
//	freopen("in.txt" , "r" , stdin);
	int T , t;

	scanf("%d" , &T);
	for(t=0; t<T; t++)
	{
		if(t) putchar('\n');
		int caseno = 0;
		while(scanf("%d" , &n) , n)
		{
			if(caseno) putchar('\n');

			init();
			printf("Case %d:\n\n" , ++caseno);
			solve();
		}
	}

	return 0;
}
