#include <stdio.h>
#include <string.h>

int n , m;
int cl[61][31];
int al[31][61];
int valid[61];
int cnt[31];
int rank[31];

void init()
{
	scanf("%d" , &m);

	memset(cl , 0 , sizeof(cl));
	memset(al , 0 , sizeof(al));

	int i , j , k;
	for(i=0; i<m; i++)
	{
		scanf("%d" , &cl[i][0]);
		for(j=1; j<=cl[i][0]; j++)
		{
			scanf("%d" , &k); k--;
			cl[i][j] = k;
			al[k][++al[k][0]] = i;
		}
	}	
}

void pre_doing()
{
	int i , j , k , t;
	for(i=0; i<n; i++) rank[i] = i;
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
			if(al[rank[i]][0] > al[rank[j]][0])
			{
				k = rank[i];
				rank[i] = rank[j];
				rank[j] = k;
			}
	for(k=0; k<n; k++)
	{
		for(i=1; i<=al[k][0]; i++)
			for(j=i+1; j<=al[k][0]; j++)
				if(cl[al[k][i]][0] > cl[al[k][j]][0])
				{
					t = al[k][i];
					al[k][i] = al[k][j];
					al[k][j] = t;
				}
	}
}

int best;

bool press(int button)
{
	for(int i=1; i<=cl[button][0]; i++)
	{
		cnt[cl[button][i]]++;
		if(cnt[cl[button][i]] > 3)
		{
			for(;i;i--)
			{
				cnt[cl[button][i]]--;
			}
			return 0;
		}
	}

	return 1;
}

void resume(int button)
{
	for(int i=1; i<=cl[button][0]; i++)
		cnt[cl[button][i]]--;
}

void search(int k , int cost)
{

	if(cost >= best) return;
	if(k == n)
	{
		best = cost;
		return ;
	}	

	int K = rank[k];
	int i , j , p;
	for(i=1; i<=al[K][0]; i++)
		if(valid[al[K][i]] < 0) valid[al[K][i]] = K;

	
	if(cnt[K] % 2 == 0)
	{
		/*
		for(i=1; i<=al[K][0]; i++)
			if(valid[al[K][i]] == K)
			{
				if(press(al[K][i]))
				{
					search(K + 1 , cost+1);
					resume(al[K][i]);
				}				
			}
		*/
		// 选三个
		if(cnt[K] == 0)
		{
			for(i=1; i<=al[K][0]; i++)
				if(valid[al[K][i]] == K)
				{
					if(press(al[K][i]))
					{
						search(K + 1 , cost + 1); // 选一个
						for(j=i+1; j<=al[K][0]; j++)
							if(valid[al[K][j]] == K)
								if(press(al[K][j]))
								{
									for(p=j+1; p<=al[K][0]; p++)
										if(valid[al[K][p]] == K)
											if(press(al[K][p]))
											{
												search(K + 1 , cost + 3);
												resume(al[K][p]);
											}
									resume(al[K][j]);
								}
						
						resume(al[K][i]);
					}
				}
		}
	}
	else{
		search(K + 1 , cost);
		if(cnt[K] == 1)
		{
			//选两个
			for(i=1; i<=al[K][0]; i++)
				if(valid[al[K][i]] == K)
				{
					if(press(al[K][i]))
					{
						for(j=i+1; j<=al[K][0]; j++)
							if(valid[al[K][j]] == K)
								if(press(al[K][j]))
								{
									search(K + 1 , cost + 2);
									resume(al[K][j]);
								}
						
						resume(al[K][i]);
					}
				}
		}
	}


	for(i=1; i<=al[K][0]; i++)
		if(valid[al[K][i]] == K) valid[al[K][i]] = -1;
}

void solve()
{
	best = 1000;

	memset(valid , 0xff , sizeof(valid));
	memset(cnt , 0 , sizeof(cnt));
	search(0 , 0);

	if(best == 1000) puts("~~~~><~~~~");
	else printf("%d\n" , best);
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
