#include <stdio.h>

int d1 , d2 , d3 , tot;

bool test(int d1 , int d2)
{
	if(d1 + d2 == d3 || d1 + d2 == d3 + 1)
	{
		if((tot - d2 - d1 - d2) % 3 == 0)
		{
			int p = (tot - d2 - d1 - d2) / 3;
			printf("%d %d %d\n" , d1 + d2 + p , d2 + p , p);
			return 1;
		}
		return 0;
	}
	return 0;
}

int main(){
	while(scanf("%d%d%d%d" , &d1 ,&d2 , &d3 , &tot) > 0)
	{
		tot += 12;
		if(test(d1 , d2)) continue;
		if(test(d1 + 1 , d2)) continue;
		if(test(d1 , d2 + 1)) continue;
		if(test(d1 + 1 , d2 + 1)) continue;
	}
	
	return 0;
}
