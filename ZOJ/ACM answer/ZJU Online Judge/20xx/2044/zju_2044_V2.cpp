#include <stdio.h>
#include <string.h>

void print(int k)
{
	if(k == 0)
	{
		printf("((A0|B0)|(A0|B0))");		
	}
	else
	{
		printf("((A%d|B%d)|(" , k , k);
		print(k-1);
		printf("|((A%d|A%d)|(B%d|B%d))))" , k , k , k , k);
	}
}

int main()
{
	int T , n;
	scanf("%d" , &T);

	while(T--)
	{
		scanf("%d" , &n);
		print(n-1);
		putchar('\n');
		if(T) putchar('\n');
	}
	
	return 0;
}