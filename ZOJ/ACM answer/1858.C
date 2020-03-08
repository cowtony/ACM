#include <stdio.h>
int main()
{
	int a[26]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
	int k=0,temp=0;
	int b[20];
	char c;
	int i,j=0;
	while(1)
	{
		if(scanf("%c",&c)==EOF) break;
		if(c=='\n')
		{
			for(i=0;i<j;i++)
				printf("%d",b[i]);
			printf("\n");
			j=0;k=0;
		}
		else
		{
			if(a[c-65]==0) k=0;
			else
			{
				if(k!=a[c-65]) {b[j++]=a[c-65];k=a[c-65];}
			}
		}
	}
	return 0;
}