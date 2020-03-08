#include <stdio.h>
int main()
{
	int a[10000][6];
	int i,j;
	int result,count,temp,le,lie,k,l;
	int cas;
	int n;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<6;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		result=0;
		for(i=0;i<6;i++)
		{
			count=0;
			temp=0;
			le=i;
			if(le==0) lie=5;
			else if(le==1) lie=3;
			else if(le==2) lie=4;
			else if(le==3) lie=1;
			else if(le==4) lie=2;
			else lie=0;
			for(k=0;k<6;k++)
			{
				if(k!=le&&k!=lie) 
				{
					if(a[0][k]>temp) temp=a[0][k];
				}
			}
			count=temp;
			for(j=1;j<n;j++)
			{
				for(l=0;l<6;l++)
				{
					if(a[j][l]==a[j-1][lie]) {le=l;break;}
				}
				if(le==0) lie=5;
				else if(le==1) lie=3;
				else if(le==2) lie=4;
				else if(le==3) lie=1;
				else if(le==4) lie=2;
				else lie=0;
				temp=0;
				for(k=0;k<6;k++)
				{
					if(k!=le&&k!=lie) 
					{
						if(a[j][k]>temp) temp=a[j][k];
					}
				}
				count+=temp;
			}
			if(count>result) result=count;
		}
		printf("%d\n",result);
	}
	return 0;
}
