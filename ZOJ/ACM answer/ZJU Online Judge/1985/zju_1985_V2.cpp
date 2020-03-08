#include <stdio.h>
#include <string.h>
#include <sys/io.h>
#include <sys/unistd.h>

#define maxn 100010
#define BUFSIZE 1024

int n;
int list[maxn];
int prev[maxn] , next[maxn];
int p , len;
char buf[BUFSIZE];

int ret;
inline int my_read()
{
	ret = 0;
	while(buf[p]!=' ' && buf[p] != '\n')
	{
		ret = ret * 10 + buf[p] - '0';
		p++;
		if(p == len)
		{
			len = read(0 , buf , BUFSIZE);
			p = 0;
		}
	}
	p++;
	if(p == len)
	{
		len = read(0 , buf , BUFSIZE);
		p = 0;
	}
	return ret;
}

void init()
{
	int i;
	for(i=1; i<=n; i++)
	{
		list[i] = my_read();
	}
}

void predoing()
{
	int i , k;

	list[0] = list[n+1] = -1;
	prev[1] = 1;
	for(i=2; i<=n; i++)
	{
		if(list[i - 1] < list[i])
		{
			prev[i] = i;
		}
		else
		{
			k = i;
			while(list[k - 1] >= list[i])
			{
				k = prev[k - 1];
			}
			prev[i] = k;
		}
	}

	next[n] = n;
	for(i=n-1; i; i--)
	{
		if(list[i + 1] < list[i])
		{
			next[i] = i;
		}
		else
		{
			k = i;
			while(list[k + 1] >= list[i])
			{
				k = next[k + 1];
			}
			next[i] = k;
		}
	}
}

void solve()
{
	double max = 0;
	double tmp;
	int i;

	for(i=1; i<=n; i++)
	{
		tmp = (double)list[i] * ((i + 1 - prev[i]) + (next[i] - i + 1) - 1);
		if(tmp > max) max = tmp;
	}

	printf("%0.lf\n" , max);
}

int main()
{	
//	freopen("in.txt" , "r" , stdin);
		 
	len = read(0 , buf , BUFSIZE);
	p = 0;

	while(1)
	{
		n = my_read();
		if(n == 0) break;
		init();
		predoing();
		solve();
	}
	
	return 0;
}
