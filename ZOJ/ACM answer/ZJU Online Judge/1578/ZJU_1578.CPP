#include <stdio.h>
#include <string.h>

typedef double stat[10][10];

int n , d;
double st[10] , ed[10];
stat g;

void init()
{
	int i , j;
	for(i=0; i<n; i++)
		scanf("%lf" , &st[i]);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%lf" , &g[i][j]);
}

void mul(stat c , stat a , stat b)
{
	memset(c , 0 , sizeof(stat));
	int i , j , k;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			for(k=0; k<n; k++)
				c[i][k] += a[i][j] * b[j][k];
}

void add(stat a , stat b)
{
	int i , j;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			a[i][j] += b[i][j];
}
/*
void power(int k , stat ret)
{
	stat w , tmp;
	int i;
	memset(ret , 0 , sizeof(stat));	
	for(i=0; i<n; i++) ret[i][i] = 1;
	memcpy(w , g , sizeof(stat));

	while(k)
	{
		if(k & 1)
		{
			mul(tmp , ret , w);
			memcpy(ret , tmp , sizeof(stat));
		}
		k= k / 2;
		mul(tmp , w , w);
		memcpy(w , tmp , sizeof(stat));
	}
}
*/
void calc(int n , stat a , stat po)
{
	if(n == 1)
	{
		memcpy(a , g , sizeof(stat));
		memcpy(po , g , sizeof(stat));
		return;
	}

	if(n % 2 == 1)
	{
		stat b;
		calc(n - 1 , b , po);		
		mul(a , b , g);
		add(a , g);
		mul(b , po , g);
		memcpy(po , b , sizeof(stat));
		return;
	}
	else
	{
		n /= 2;
		stat b;		
		calc(n , b , po);
		mul(a , b , po);
		add(a , b);
		mul(b , po , po);
		memcpy(po , b , sizeof(stat));
		return;
	}
}



void solve()
{	
	stat a , po;	
	calc(d , a , po);
	int i , j;
	memset(ed , 0 , sizeof(ed));
	
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			ed[j] += st[i] * a[i][j];
	for(i=0; i<n-1; i++)
		printf("%.2lf " , ed[i]);
	printf("%.2lf\n" , ed[n-1]);
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	while(scanf("%d%d" , &n , &d) > 0)
	{
		init();
		solve();
	}

	return 0;
}