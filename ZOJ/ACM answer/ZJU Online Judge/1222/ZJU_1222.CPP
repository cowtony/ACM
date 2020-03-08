#include <stdio.h>
#include <string.h>

#define maxlen 200

struct BigInt
{
	int l , c[maxlen];
} a;
char s[maxlen];

void assign()
{
	a.l = strlen(s);
	memset(a.c , 0 ,  sizeof(a.c));
	for(int i=0; i<a.l; i++)
		a.c[a.l - i] = s[i] - '0';
}

const int last_digit[] = 
{1 , 1 , 2 , 6 , 4 , 4 , 4 , 8 , 4 , 6};
const int p10 = 6;

int ret , cnt;

void division()
{
	int c = 0;
	for(int i=a.l; i>0; i--)
	{
		a.c[i] += c * 10;
		c = a.c[i] % 5;
		a.c[i] /= 5;
	}
	while(a.l > 1 && a.c[a.l] == 0) a.l--;
}

void solve()
{
	if(a.l == 1 && a.c[1] <= 1)
	{
		puts("1"); return;
	}

	ret = 1;
	cnt = 0;

	while(1)
	{
		if(a.l == 1 && a.c[1] <= 1)
		{
			break;
		}
		if(a.l > 1) ret *= 6;
		ret = ret * last_digit[a.c[1]] % 10;
		division();
		cnt = (cnt + a.c[2] * 10 + a.c[1]) % 4;
	}

	while(cnt--)
	{
		ret /= 2;
		if(ret % 2 == 1) ret += 5;
	}

	printf("%d\n" , ret);
}


int main()
{
//	freopen("in.txt" , "r" , stdin);

	while(scanf("%s" , s) > 0)
	{
		assign();
		solve();
	}
	
	return 0;
}
