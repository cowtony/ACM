#include <stdio.h>

char f[1000000];

int main()
{
	f[0] = 1; f[1] = 2;
	for(int i=2; i<1000000; i++)
		f[i] = (f[i-1] + f[i-2]) % 3;
	int n;
	while(scanf("%d" , &n) > 0)
	{
		if(f[n]) puts("no");
		else puts("yes");
	}
	return 0;
}