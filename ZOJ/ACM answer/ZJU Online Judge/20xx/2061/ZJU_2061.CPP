#include <stdio.h>
#include <string.h>

int n , m;
bool flag;
short int A[1000];

void mul(int k)
{
	if(k == n + 1 && !flag)
	{
		flag = 1; return;
	}

	A[1] *= k;
	for(int i=2; i<=A[0]; i++)		
	{
		A[i] = A[i] * k + A[i-1] / 10;
		A[i-1] %= 10;
	}
	while(A[A[0]] >= 10)
	{
		A[A[0]+1] = A[A[0]] / 10;
		A[A[0]] %= 10;
		A[0]++;
	}
}

void solve()
{
	flag = 0;
	memset(A , 0 , sizeof(A));
	A[0] = A[1] = 1;

	int i;
	for(i=2; i<=n+m; i++)
	{
		mul(i);
	}
	mul(n+1-m);
	for(i=A[0]; i; i--)
		printf("%d" , A[i]);
	putchar('\n');
}

int main()
{

	int caseno = 0;

	while(1)
	{
		scanf("%d%d" , &n , &m);
		if(!n && !m) break;
		printf("Test #%d:\n" , ++caseno);
		if(n < m) puts("0");
		else solve();		
	}
	return 0;
}
