#include <stdio.h>

int a , b;

bool check(int a , int b)
{
	if(b % a == 0) return 1;
	if(b - a > a) return 1;
	return !check(b - a , a);
}

int main()
{
	int t;

	while(scanf("%d%d" , &a , &b) , a)
	{
		if(a > b) t = a , a = b , b = t;
		if(check(a , b)) puts("Stan wins");
		else puts("Ollie wins");		
	}

	return 0;
}



