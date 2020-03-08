#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 100000;
int f[MAXN], count[MAXN];
void find(int x)
{
	int p=x,q;
	while(f[x]!=x)
	{
		x=f[x];
	}
	while (f[p] != p)
	{
		q=f[p]; 
		f[p]=x; 
		p=q;
	}
}
void merge(int x, int y)
{
	count[f[y]]=count[f[x]]+count[f[y]];
	f[f[x]]=f[y];
}
int main()
{
	int m, n, p, q, cases = 0;
	char ch;
    int i;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		++cases;
		if (cases != 1) printf("\n");
		printf("%s%d%s\n", "Case ", cases, ":");
		for (i=0;i!=m+1;++i)
		{
			f[i]=i; 
			count[i]=1;
		}
		ch=getchar();
		for (i=0;i!=n; ++i)
		{
			ch = getchar();
			if (ch == 'M')
			{
				scanf("%d%d", &p, &q);
				find(p); 
				find(q);
				if (f[p] != f[q]) 
					merge(p, q);
				ch = getchar();
			}
			if (ch == 'Q')
			{
				scanf("%d", &p);
				find(p);
				printf("%d\n", count[f[p]]);
				ch = getchar();
			}
		}
	}
	return 0;
}
