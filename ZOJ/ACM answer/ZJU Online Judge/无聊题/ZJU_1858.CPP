#include <stdio.h>
#include <string.h>

int len;
char buf[100];

char trans(char a)
{
	if(a=='B' || a=='F' || a=='P' || a=='V') return ('1');
	if(a=='C' || a=='G' || a=='J' || a=='K'
	|| a=='Q' || a=='S' || a=='X' || a=='Z') return ('2');
	if(a=='D' || a=='T') return ('3');
	if(a=='L') return ('4');
	if(a=='M' || a=='N') return ('5');
	if(a=='R') return ('6');
	return 0;
}

int main()
{
	int i , len;
	char prev , curt;
	while(scanf("%s" , buf) > 0)
	{
		len = strlen(buf);
		prev = 0;
		for(i=0; i<len; i++)
		{
			curt = trans(buf[i]);
			if(curt == 0)
			{
				prev = 0;
				continue;
			}
			if(prev != curt)
			{
				putchar(curt);
				prev = curt;
			}
		}
		putchar('\n');
	}
	return 0;
}