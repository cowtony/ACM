#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n , W , H;
struct point { int x , y ; } list[110];

void init()
{
	scanf("%d%d" , &W , &H);
	for(int i=0; i<n; i++)
	{
		scanf("%d%d" , &list[i].x , &list[i].y);
	}
	list[n].x = 0; list[n].y = 0; n++;
	list[n].x = W; list[n].y = 0; n++;
	list[n].x = 0; list[n].y = H; n++;
	list[n].x = W; list[n].y = H; n++;
}

int r , a , b;

int cmp_x(const void* a , const void* b)
{
	return ((point*)a)->x - ((point*)b)->x;
}

int cmp_y(const void* a , const void* b)
{
	return ((point*)a)->y - ((point*)b)->y;
}

inline int min(int a , int b)
{
	return a < b ? a : b;
}

inline int max(int a , int b)
{
	return a > b ? a : b;
}

inline void renew(int x , int y , int l)
{
	if(l > r)
	{
		a = x , b = y , r = l;
	}
}

void solve()
{
	r = -1;

	int top , bottom , i , j;

	qsort((void *)list , n , sizeof(point) , cmp_y);

	bottom = 0;
	for(i=0; i<n; i++)
	{
		renew(0 , bottom , min(W , list[i].y - bottom));
		bottom = list[i].y;
	}

	qsort((void *)list , n , sizeof(point) , cmp_x);

	for(i=0; i<n; i++)
	{
		top = H;
		bottom = 0;

		for(j=i+1; j<n; j++)
		{			
			renew(list[i].x , bottom , min(top - bottom , list[j].x - list[i].x));
		
			if(list[j].y > list[i].y)
				top = min(top , list[j].y);			
			else
				bottom = max(bottom , list[j].y);			
		}
	}

	for(i=n-1; i>0; i--)
	{
		top = H;
		bottom = 0;
		for(j=i-1; j>=0; j--)
		{			
			renew(list[j].x , bottom , min(top - bottom , list[i].x - list[j].x));
			
			if(list[j].y > list[i].y)
				top = min(top , list[j].y);			
			else
				bottom = max(bottom , list[j].y);			
		}
	}
	
	printf("%d %d %d\n" , a , b , r);
}

int main()
{
	freopen("cricket.in.txt" , "r" , stdin);

	while(scanf("%d" , &n) > 0)
	{
		init();
		solve();
	}

	return 0;
}