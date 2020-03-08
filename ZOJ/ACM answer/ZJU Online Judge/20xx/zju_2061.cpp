#include <stdio.h>
#include <string.h>

int n , m;

void solve()
{
}

int main()
{
	int caseno = 0;
	while(scanf("%d%d" , &n , &m) , n || m)
	{
		printf("Test #%d:\n" , ++caseno);
		if(m > n) puts("0");
		else solve();
	}
	
	return 0;
}
