#include <stdio.h>
#include <string.h>

int n , m;
char g[20][20];

int k , p , p2;
int lab[20][20];
int bomb[400];
bool valid[400];
int list[50];

int cont[50][50] , cnt[50];

void init()
{
	for(int i=0; i<n; i++)
		scanf("%s" , g[i]);
}

const int dir[4][2] =
{-1,0 , 1,0 , 0,-1 , 0,1};

int try_bomb(int x , int y)
{
	int x0 , y0;
	int stat = 0;

	for(int i=0; i<4; i++)
	{
		x0 = x; y0 = y;
		while(1)
		{
			x0 += dir[i][0]; y0 += dir[i][1];
			if(g[x0][y0] == '*') break;
			if(g[x0][y0] == '#')
			{
				stat |= (1<<lab[x0][y0]);
				break;
			}
		}
	}
	return stat;
}


void predoing()
{
	int i , j , stat;

	// 给每个#标号
	k = 0;
	memset(lab , 0xff , sizeof(lab));

	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			if(g[i][j] == '#')
			{
				lab[i][j] = k++;
			}
	
	// 计算每个空格能炸到的#
	p2 = 0;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			if(g[i][j] == '.')
			{
				stat = try_bomb(i , j);
				if(stat)
				{
					valid[p2] = 1;
					bomb[p2] = stat;
					p2++;
				}
			}

	// 剔除没用的
	p = 0;
	for(i=0; i<p2; i++)
	{
		for(j=0; j<p2; j++)
			if(bomb[i] != bomb[j] && (bomb[i] & bomb[j]) == bomb[i])
			{
				valid[i] = 0;
				break;
			}
	}

	for(i=0; i<p2; i++)
	{
		if(!valid[i]) continue;
		for(j=0; j<i; j++)
			if(bomb[i] == bomb[j])
			{
				break;
			}
		if(j == i)
		{			
			list[p] = bomb[i];
			p++;
		}
	}

	// 分类
	memset(cnt , 0 , sizeof(cnt));
	for(i=0; i<p; i++)
	{
		for(j=0; j<k; j++)
			if(list[i] & (1<<j))
			{				
				cont[j][cnt[j]] = i;
				cnt[j]++;
			}
	}
}

#define UPK 9

int best , MODOL;
int f[1<<UPK];

inline void renew(int stat , int cost)
{
	if(f[stat] < 0 || cost < f[stat])
	{
		f[stat] = cost;
	}
}

void dp()
{
	int k1 = k > UPK ? UPK : k;
	MODOL = (1<<k1) - 1;
	int i , j;

	memset(f , 0xff , sizeof(f));
	f[0] = 0;
	for(i=0; i<=MODOL; i++)
	{
		if(f[i] < 0) continue;
		for(j=0; j<p; j++)
			renew((i | list[j]) & MODOL , f[i] + 1);
	}
	for(i=MODOL; i; i--)
	{
		for(j=0; j<k1; j++)
			if((i & (1<<j)))
			{
				renew(i ^ (1<<j) , f[i]);
			}
	}
}

void OLE()
{
	while(1) puts("XXX");
}

void search(int p , int cost , int stat)
{		
	if(cost + f[(stat & MODOL) ^ MODOL] >= best) return;
	if(p < UPK)
	{
		best = cost + f[(stat & MODOL) ^ MODOL];
		return;
	}	
	if(stat & (1<<p))
	{
		search(p - 1 , cost , stat);
	}
	else
	{		
		for(int i=0; i<cnt[p]; i++)
			search(p - 1 , cost + 1 , stat | list[cont[p][i]]);
	}	
}

void solve()
{
	if(k <= UPK)
	{
		printf("%d\n" , f[(1<<k)-1]);
		return;
	}

	best = k;
	search(k-1 , 0 , 0);
	
	printf("%d\n" , best);
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	while(scanf("%d%d" , &n , &m) > 0)
	{
		init();
		predoing();
		dp();
		solve();
	}

	return 0;
}