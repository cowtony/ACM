#include <stdio.h>
#include <string.h>
#include <math.h>

char s[500010];
int len;

int guess_number()
{
	int p = 1 , r = 100000 , m;
	double ret;
	// L-1 <= NlgN < L
	while(p <= r)
	{
		m = (p + r) >> 1;
		ret = m * log10(m);
		if(len-1 <= ret && ret < len) return m;
		if(ret > len) r = m - 1;
		else p = m + 1;
	}
	return 0;
}

bool check_number(int n)
{
	int c = 0;
	int i;
	for(i=0; i<len; i++)
	{
		c = (c * 10 + s[i] - '0') % 11;
	}

	int ret = 1 , w = n % 11;
	while(n)
	{
		if(n % 2)
		{
			ret = ret * w % 11;
		}
		n /= 2;
		w = w * w % 11;
	}

	return c == ret;
}

void solve()
{
	if(len == 1)
	{
		if(s[0] == '1') puts("1");
		else if (s[0] == '4') puts("2");
		else puts("-1");
		return;
	}

	int n = guess_number();
	if(check_number(n))
	{
		printf("%d\n" , n);
	}
	else puts("-1");
}

int main()
{
	int T;
	scanf("%d" , &T);

	while(T--)
	{
		scanf("%s" , s);
		len = strlen(s);
		solve();
	}

	return 0;
}