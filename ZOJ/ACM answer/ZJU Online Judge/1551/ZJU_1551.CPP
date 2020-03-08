#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n , W , H;
struct point
{
	int x , y;
} list[101];
int vx[110];
int valid[110];

void init()
{
	scanf("%d%d" , &W , &H);
	for(int i=0; i<n; i++)
	{
		scanf("%d%d" , &list[i].x , &list[i].y);
		vx[i+1] = list[i].x;
	}
	vx[0] = 0;
	vx[n+1] = W;
}

int cmp_int(const void* a , const void* b)
{
	return *(int*)a - *(int*)b;
}

int cmp_point(const void* a , const void* b)
{
	return ((point*)a)->y - ((point*)b)->y;
}

int left , right;
int max , x0 , y0;

inline int min(int a , int b)
{
	return a < b ? a : b;
}

void renew(int bottom , int top)
{
	int tmp = min(top - bottom , right - left);
	if(tmp > max)
	{
		max = tmp;
		x0 = left;
		y0 = bottom;
	}
}

void work()
{
	int curt = 0;
	for(int i=0; i<n; i++)
		if(list[i].x > left && list[i].x < right)
		{
			renew(curt , list[i].y);
			curt = list[i].y;
		}
	renew(curt , H);
}

void solve()
{
	qsort((void*)vx , n+1 , sizeof(int) , cmp_int);
	qsort((void*)list , n , sizeof(point) , cmp_point);

	valid[0] = 1;

	max = 0;

	int i , j;
	for(i=1; i<=n+1; i++)
		if(vx[i] == vx[i-1]) valid[i] = 0; else valid[i] = 1;

	for(i=0; i<=n; i++)
		if(valid[i])
		{
			left = vx[i];
			for(j=i+1; j<=n+1; j++)
				if(valid[j])
				{
					right = vx[j];
					work();
				}
		}
	
	printf("%d %d %d\n" , x0 , y0 , max);
}

int main()
{
	freopen("in.txt" , "r" , stdin);

	while(scanf("%d" , &n) > 0)
	{
		init();
		solve();
	}	
	
	return 0;
}
