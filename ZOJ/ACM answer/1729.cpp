#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int cas;
	char c[200002];
	int i, j;
	int num;
	scanf("%d", &cas);
	while(cas--)
	{
		int len;
		scanf("%d", &len);
		scanf("%s", c);
		for(i=len; i<2*len; i++)
		{
			c[i] = c[i-len];
		}
		i = 0; j = 1;
		while(j<len)
		{
			int k = i, l = j;
			int ix;
			for(ix=0; ix<len; ix++)
			{
				if(c[k] != c[l]) break;
				k++;
				l++;
			}
			if(ix==len) break;
			if(c[k] > c[l])
			{
				i = k+1;
				if(i>j)
				{
					int temp = j;
					j = i;
					i = temp;
				}
				else if(i==j) j++;
			}
			else
			{
				j = l+1;
			}
		}
		printf("%d\n", i);
	}
	return 0;
}