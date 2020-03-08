#include <stdio.h>
#include <string.h>

char line[100];
int pos[1000];

int main()
{

	int ret , len , k;
	int p , r;
	while(1)
	{
		
		if(gets(line) <= 0) break;
		pos[0] = -1; ret = -1; len = 0; k = 0;

		while(strcmp(line , ""))
		{
			if(line[0] == '0')
			{
				ret++; len++;
				++k;
				pos[k] = len;
			}
			else
			{
				sscanf(line , "%d%d" , &p , &r);
				p = len - p;
				while (p < pos[k])
				{
					ret--;
					k--;
				}
				ret++;
				++k;
				pos[k] = len += r;
							
			}
			gets(line);
		}

		printf("%d\n" , ret);
	}
	return 0;
}