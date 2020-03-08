#include <stdio.h>
#include <string.h>

bool f[(1<<15) + 10];
int prime[10000] , cnt;
int n;

void gen_prime()
{
	memset(f , 1 , sizeof(f));
	cnt = 0;
	f[0] = f[1] = 0;
	
	int i , k;
	for(i=2; i<32768; i++)
		if(f[i])
		{
			prime[cnt++] = i;
			k = i + i;
			while(k < 32768)
			{
				f[k] = 0;
				k += i;
			}
		}
}

void solve()
{
	int ret = 0;
	for(int i=0; i<cnt; i++)
	{
		if(prime[i] > n / 2) break;
		if(f[n - prime[i]]) ret++;
	}
	printf("%d\n" , ret);
}

int main()
{
	gen_prime();

	while(scanf("%d" , &n) , n)
	{
		solve();
	}
	
	return 0;
}
