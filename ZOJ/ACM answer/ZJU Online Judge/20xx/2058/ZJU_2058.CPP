#include <stdio.h>
#include <string.h>

int n;
char buf[110];

void do_line(int len , int& a , int& b)
{
	scanf("%s" , buf);
	int i;
	for(i=0; i<len; i++)
		if(buf[i] != '?')
		{
			if((i % 2 == 0) != (buf[i] == '@'))
			{
				a = b = len / 2;
			}
			else
			{
				a = b = len - len / 2;
			}

			return;
		}
	b = len / 2;
	a = len - len / 2;
}

int main(){
	int max , min;
	int dx , dm , i;

	while(scanf("%d" , &n) > 0 && n > 0)
	{
		max = min = 0;
		for(i=1; i<=n; i++)
		{
			do_line(i , dx , dm);
			max += dx;
			min += dm;
		}
		printf("%d %d\n" , max , min);
	}
	
	return 0;
}
