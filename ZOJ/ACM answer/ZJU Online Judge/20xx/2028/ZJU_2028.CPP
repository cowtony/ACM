#include <stdio.h>
#include <string.h>

char a[200] , b[200];
int la , lb;

int div(char a[] , int len)
{
	int c = 0;
	for(int i = 0 ; i < len; i ++)
	{
		c = c * 10 + a[i] - '0';
		c %= 8;
	}
	return c;
}

int main()
{
	while(1)
	{
		if(scanf("%s%s" , a , b) < 0) break;
		la = strlen(a);
		lb = strlen(b);

		if(la == 1 && a[0] == '1')
		{
			puts(b);
		}
		else if(lb == 1 && b[0] == '1')
		{
			puts(a);
		}
		else
		{
			int aa = div(a , la);
			int bb = div(b , lb);
			
			if(aa * bb % 8 == 0) puts("Yes");
			else if(aa * bb % 4 == 0) puts("4");
			else printf("%d\n" , aa * bb % 4);
		}
		
	}
	
	return 0;
}
