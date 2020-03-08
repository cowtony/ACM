#include <stdio.h>
#include <string.h>

int n , m;
int swit[62];
int cnt[62];
short bits[(1<<15) + 10];
int tot[62];
int got[62];

void init()
{
	int i , j , k;
	scanf("%d" , &m);

	for(i=0; i<m; i++)
	{
		scanf("%d" , cnt + i);
		swit[i] = 0;
		for(j=0; j<cnt[i]; j++)
		{
			scanf("%d" , &k); k--;
			swit[i] |= (1<<k);
		}
		for(j=0; j<i; j++)
			if(swit[i] == swit[j]) break;
		if(j < i)
		{
			i-- , m--;
		}
	}
}

void doit_first()
{
	int i , j;
	for(i=0; i<(1<<15); i++)
	{
		bits[i] = 0;
		for(j=0; j<15; j++)
			if(i & (1<<j)) bits[i]++;
	}
}

void pre_doing()
{
	int i , j , t;
	for(i=0; i<m; i++)
		for(j=i+1; j<m; j++)
			if(cnt[i] < cnt[j])
			{
				t = cnt[i]; cnt[i] = cnt[j]; cnt[j] = t;
				t = swit[i]; swit[i] = swit[j]; swit[j] = t;
			}

	tot[m] = got[m] = 0;
	for(i=m-1; i>=0; i--)
	{
		tot[i] = tot[i+1] + cnt[i];
		got[i] = (got[i+1] | swit[i]);
	}
}

inline short count_bit(int k)
{
	return bits[(k >> 15)] + bits[k & ((1<<15)-1)];
}

int Limit , target;

bool search(int k , int cost , int p0 , int p1 , int p2 , int p3)
{	
	if(cost > Limit || m - k < Limit - cost) return 0;

	if((p1 | p3) == target) return 1;

	if(k == m) return 0;
	if(count_bit(p0 | p2) > tot[k]) return 0;
	if((p0 | p2) & (~got[k])) return 0;
	
	
	int pp0 = p0 , pp1 = p1 , pp2 = p2 , pp3 = p3;

	if(search(k + 1 , cost , pp0 , pp1 , pp2 , pp3)) return 1;

	if((swit[k] & p3) == 0)
	{
		p3 |= (p2 & swit[k]);
		p2 &= ~p3;
		p2 |= (p1 & swit[k]);
		p1 &= ~p2;
		p1 |= (p0 & swit[k]);
		p0 &= ~p1;

		if(search(k + 1 , cost + 1 , p0 , p1 , p2 , p3)) return 1;
	}	

	return 0;
}

void solve()
{
	target = (1<<n) - 1;

	for(Limit=1; Limit <= m; Limit++)
	{
		if(search(0 , 0 , target , 0 , 0 , 0)) 
		{
			printf("%d\n" , Limit);
			return;
		}
	}

	puts("~~~~><~~~~");
}

int main(){
//	freopen("in.txt" , "r" , stdin);
	
	doit_first();

	while(scanf("%d" , &n) > 0)
	{
		init();
		pre_doing();
		solve();
	}
	
	return 0;
}
