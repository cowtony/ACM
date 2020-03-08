#include <stdio.h>
#include <string.h>

char buf[210];
const int dir[4][2] = {{10,0} , {0,-10} , {-10,0} , {0,10}};

int main()
{
	int x , y , p , len , f;	

	while( scanf("%s" , buf) > 0 )
	{
		len = strlen(buf);
		x = 310 ; y = 420; f = 0;

		puts("300 420 moveto");
		puts("310 420 lineto");

		for(p=0; p<len; p++)
		{
			if(buf[p] == 'V') f = (f + 3) % 4;
			else f = (f + 1) % 4;
			
			x += dir[f][0];
			y += dir[f][1];

			printf("%d %d lineto\n" , x , y);
		}		

		printf("stroke\nshowpage\n");
	}
	
	return 0;
}
