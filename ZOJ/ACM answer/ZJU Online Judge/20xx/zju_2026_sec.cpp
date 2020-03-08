#include <stdio.h>
#include <string.h>

int n , m;
int cl[61][31];
int cnt[31];
int rank[61];

void init()
{
	scanf("%d" , &m);

	memset(cl , 0 , sizeof(cl));

	int i , j , k;
	for(i=0; i<m; i++)
	{
		scanf("%d" , &cl[i][0]);
		for(j=1; j<=cl[i][0]; j++)
		{
			scanf("%d" , &k);k--;
			cl[i][j] = k;
		}
	}
}

void pre_doing()
{
	int i , j , t;
	for(i=0; i<m; i++)
		rank[i] = i;
	for(i=0; i<m; i++)
		for(j=i+1; j<m; j++)
			if(cl[rank[i]][0] > cl[rank[j]][0])
			{
				t = rank[i];
				rank[i] = rank[j];
				rank[j] = t;
			}
}

int Limit , p , r;
bool search(int k , int c , int cost)
{
	if(cost > Limit) return 0;
	if(c == 0)
	{		
		return 1 ;
	}
	if(k == m) return 0;

	int i;
	bool flag = 1;
	//press
	for(i=1; i<=cl[rank[k]][0]; i++)
	{
		cnt[ cl[rank[k]][i] ]++;
		if(cnt[ cl[rank[k]][i] ] & 1) c--;
		else c++;

		if(cnt[ cl[rank[k]][i] ] > 3) flag = 0;
	}

	if(flag)
	{
		if(search(k + 1 , c , cost + 1))return 1;
	}

	//resume
	for(i=1; i<=cl[rank[k]][0]; i++)
	{
		cnt[ cl[rank[k]][i] ]--;
		if(cnt[ cl[rank[k]][i] ] & 1) c--;
		else c++;		
	}

	//donot press
	if(search(k + 1 , c , cost)) return 1;
	return 0;
}

void solve()
{
	memset(cnt , 0 , sizeof(cnt));

	p = 1; r = m;
	bool flag = 0;
	while(p < r)
	{
		Limit = (p + r) >> 1;
		if(search(0 , n , 0)) r = Limit , flag = 1;
		else p = Limit + 1;
	}

	if(!flag) puts("~~~~><~~~~");
	else printf("%d\n" , r);
}

int main()
{
	freopen("in.txt" , "r" , stdin);
	while(scanf("%d" , &n) > 0)
	{
		init();
		pre_doing();
		solve();
	}

	return 0;
}