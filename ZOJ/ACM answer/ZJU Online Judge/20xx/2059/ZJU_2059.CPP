#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int f0[1010] , f1[1010];

inline void renew(int k , int c)
{
	if(k <= 1000)
	{
		if(c > f1[k]) f1[k] = c;
	}
}

void solve()
{
	memset(f0 , 0xff , sizeof(f0));
	f0[0] = 0;

	int i , j , k;
	for(i=0; i<n; i++)
	{
		scanf("%d" , &k);
		memcpy(f1 , f0 , sizeof(f0));

		for(j=0; j<=1000; j++)
			if(f0[j] >= 0)
			{
				renew(j + k , f0[j] + k);
				renew(abs(j - k) , f0[j] + k);
			}
		memcpy(f0 , f1 , sizeof(f0));
	}

	if(f0[0] > 0) printf("%d\n" , f0[0] / 2);
	else puts("Sorry");

}

int main()
{
	while(scanf("%d",  &n) , n > 0)
	{
		solve();
	}
	
	return 0;
}
