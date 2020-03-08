#include <stdio.h>
#include <string.h>
int main()
{
	int north,east,west,south,bottom,top;
	int temp,num;
	int i;
	char s[6];
	while(scanf("%d%*c",&num))
	{
		if(num==0) break;
		north=2;
		west=3;
		east=4;
		south=5;
		top=1;
		bottom=6;
		for(i=0;i<num;i++)
		{
			gets(s);
			if(strcmp(s,"north")==0)
			{
				temp=bottom;
				bottom=north;
				north=top;
				top=south;
				south=temp;
			}
			else if(strcmp(s,"south")==0)
			{
				temp=bottom;
				bottom=south;
				south=top;
				top=north;
				north=temp;
			}
			else if(strcmp(s,"east")==0)
			{
				temp=bottom;
				bottom=east;
				east=top;
				top=west;
				west=temp;
			}
			else
			{
				temp=bottom;
				bottom=west;
				west=top;
				top=east;
				east=temp;
			}
		}
		printf("%d\n",top);
	}
	return 0;
}
