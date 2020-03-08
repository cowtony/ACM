#include <stdio.h>
#include <string.h>
int main()
{
	char str[20];
	int i,j,count,t,k,sum;
	while(gets(str)&&strcmp(str,"0 0")!=0)
	{
		count=0;
		for(i=0;;i++)
			if(str[i]==' ') break;
		t=0;
		for(j=i-1,k=strlen(str)-1;j>=0&&k>i;j--,k--)
		{
			sum=(str[j]-48)+(str[k]-48)+t;
			t=sum/10;
			count+=t;
		}
		if(j>=0)
		{
			for(k=j;k>=0;k--)
			{
				sum=(str[k]-48)+t;
				t=sum/10;
				count+=t;
			}
		}
		else if(k>i)
		{
			for(j=k;j>i;j--)
			{
				sum=(str[j]-48)+t;
				t=sum/10;
				count+=t;
			}
		}
		if(count==0) printf("No carry operation.\n");
		else if(count==1) printf("1 carry operation.\n");
		else printf("%d carry operations.\n",count);
	}
	return 0;
}


