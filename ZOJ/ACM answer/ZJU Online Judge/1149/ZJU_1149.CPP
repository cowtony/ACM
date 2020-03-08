#include <stdio.h>
#include <string.h>

int sum;
int cnt[10];
bool f[30 * (1+2+3+4+5+6) + 100];

void solve()
{
	memset(f , 0 , sizeof(f)); f[0] = 1;
	sum /= 2;
	int i , k;
	for(i=1; i<=6; i++)
	{
		while(cnt[i]--)
		{
			for(k=sum-i; k>=0; k--)
				if(f[k]) f[k+i] = 1;
		}
	}
	if(f[sum]) puts("Can be divided.");
	else puts("Can't be divided.");
}

int main()
{
	int i;
	int caseno = 0;
	while(1)
	{
		sum = 0;
		for(i=1; i<=6; i++)
		{
			scanf("%d" , &cnt[i]);
			while(cnt[i] >= 30)
			{
				cnt[i] -= 2;
			}
			sum += cnt[i] * i;
		}
		if(sum == 0) break;

		printf("Collection #%d:\n" , ++caseno);
		if(sum % 2) puts("Can't be divided.");
		else solve();
		putchar('\n');
	}

	return 0;
}