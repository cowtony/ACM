#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxn 201

int n;
struct rect
{
	double x1 , y1 , x2 , y2;
} list[maxn];
double lx[maxn*2] , ly[maxn*2];
int cx , cy;

int m;
struct op
{
	int y1 , y2 , key;
	double x;
} s[maxn*2];

#define left(x) ((x)<<1)
#define right(x) (((x)<<1)|1)
const int maxlen = 1<<9; // 2^9 = 512
int cover[maxlen * 2 + 10];

void init()
{
	cx = 0 , cy = 0; m = 0;
	for(int i=0; i<n; i++)
	{
		scanf("%lf%lf%lf%lf" , &list[i].x1 , &list[i].y1 , &list[i].x2 , &list[i].y2);
		lx[cx++] = list[i].x1; lx[cx++] = list[i].x2;
		ly[cy++] = list[i].y1; ly[cy++] = list[i].y2;
	}
}

int comp(const double& a , const double& b)
{
	if(a == b) return 0;
	if(a < b) return -1;
	return 1;
}

int cmp_double(const void* a , const void* b)
{
	return comp(*(double*)a , *(double*)b);
}

int cmp_op(const void* a , const void* b)
{
	return comp(((op*)a)->x , ((op*)b)->x);
}

int b_search(double key)
{
	int p = 0 , r = cy - 1 , m;
	while(p <= r)
	{
		m = (p + r)>>1;
		if(ly[m] == key) return m + 1;
		if(key < ly[m]) r = m - 1;
		else p = m + 1;
	}
	return -1;
}

void predoing()
{
	qsort((void*)lx , cx , sizeof(double) , cmp_double);
	qsort((void*)ly , cy , sizeof(double) , cmp_double);

	int px , py , i;
	px = py = 0;
	for(i=1; i<cx; i++)
	{
		if(lx[i] != lx[px])
		{
			lx[++px] = lx[i];
		}
		if(ly[i] != ly[py])
		{
			ly[++py] = ly[i];
		}
	}
	cx = px + 1; cy = py + 1;

	for(i=0; i<n; i++)
	{
		s[m].y1 = s[m+1].y1 = b_search(list[i].y1);
		s[m].y2 = s[m+1].y2 = b_search(list[i].y2);
		s[m].x = list[i].x1; s[m].key = 1;
		s[m+1].x = list[i].x2; s[m+1].key = -1;
		m+=2;
	}

	qsort((void*)s , m , sizeof(op) , cmp_op);
}

void insert(int idx , int st , int ed , int p , int r , int key)
{
	if(st == p && ed == r)
	{
		cover[idx] += key;
	}
	else
	{
		int m = (p + r) >> 1;
		if(ed <= m) insert(left(idx) , st , ed , p , m , key);
		else if(st >= m) insert(right(idx) , st , ed , m , r , key);
		else
		{
			insert(left(idx) , st , m , p , m , key);
			insert(right(idx) , m , ed , m , r , key);
		}
	}
}

double sum(int idx , int p , int r)
{
	if(cover[idx])
	{
		return ly[r-1] - ly[p-1];
	}
	else if(p + 1 == r) return 0;
	else
	{
		int m = (p + r) >> 1;
		return sum(left(idx) , p , m) + sum(right(idx) , m , r);
	}
}

void solve()
{
	memset(cover , 0 , sizeof(cover));
	double area = 0;
	int i;
	for(i=0; i<m-1; i++)
	{
		insert(1 , s[i].y1 , s[i].y2 , 1 , maxlen , s[i].key);
		area += sum(1 , 1 , maxlen) * (s[i+1].x - s[i].x);
	}
	printf("Total explored area: %.2lf\n" , area);
}

int main()
{
//	freopen("in.txt" , "r" , stdin);
	int caseno = 0;

	while(1)
	{
		scanf("%d" , &n);
		if(n == 0) break;

		printf("Test case #%d\n" , ++caseno);
		init();
		predoing();
		solve();
		putchar('\n');
	}

	return 0;
}