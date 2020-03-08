#include <stdio.h>
#include <string.h>

int n , k;
short int w[110];
short int v[110][110];
short int ans[110] , num[110];


void init()
{
	scanf("%d%d" , &n , &k);
	int i , j;
	char ch;
	memset(v , 0 , sizeof(v));
	for(i=0; i<k; i++)
	{
		scanf("%d" , &num[i]);
		num[i] *= 2;
		for(j=0; j<num[i]; j++)
		{
			scanf("%d" , &v[i][j]);
		}
		scanf("%1s" , &ch);
		if(ch == '<') ans[i] = -1;
		else if(ch == '=') ans[i] = 0;
		else ans[i] = 1;
	}
}

bool check()
{
	int cnt;
	int i , j;
	for(i=0; i<k; i++)
	{
		cnt = 0;
		for(j=0; j<num[i]/2; j++)
			cnt += w[v[i][j]];
		for(; j<num[i]; j++)
			cnt -= w[v[i][j]];
		if(cnt != ans[i]) return 0;
	}
	return 1;
}

void solve()
{
	int ret = 0;
	memset(w , 0 , sizeof(w));
	for(int i=1; i<=n; i++)
	{
		w[i] = 1; 
		if(check())
		{
			if(ret){ puts("0"); return; }
			ret = i;
		}
		else
		{
			w[i] = -1; 
			if(check())
			{
				if(ret){ puts("0"); return; }
				ret = i;
			}			
		}
		w[i] = 0;
	}
	printf("%d\n" , ret);
}

int main()
{
	//freopen("in.txt" , "r" , stdin);

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