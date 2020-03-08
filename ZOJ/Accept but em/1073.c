#include <stdio.h>
int main()
{
	char str[61];
	int a[60];
	int b[60][60];
	int i,j,k,l,t,count,p1,p2;
	while(1)
	{
		if(scanf("%c",&str[0])==EOF) break;
		a[0]=str[0]-48;
		for(i=1;;i++)
		{
			scanf("%c",&str[i]);
			if(str[i]=='\n') break;
			a[i]=str[i]-48;
		}
		for(j=0;j<i;j++)
		{
			for(k=0;k<i;k++)
			{
				b[j][k]=a[k]*(j+1);
			}
		}
		for(j=0;j<i;j++)
		{
			l=0;
			for(k=i-1;k>=0;k--)
			{
				t=b[j][k];
				b[j][k]=(t+l)%10;
				l=(t+l)/10;
			}
			if(l!=0) break;
		}
		if(l!=0) 
		{
			for(j=0;j<i;j++)
			{
				printf("%d",a[j]);
			}
			printf(" is not cyclic\n");
		}
		else 
		{
			t=0;
			for(j=1;j<i;j++)
			{
				for(k=0;k<i;k++)
				{
					count=0;
					if(b[0][k]==b[j][0])
					{
						for(p1=k;p1<i;p1++)
						{
							if(b[0][p1]==b[j][p1-k]) count++;
						}
						for(p2=0;p2<k;p2++)
						{
							if(b[0][p2]==b[j][p1-k+p2]) count++;
						}
						if(count==i) break;
					}
				}
				if(count!=i) {t=1;break;}
			}
			for(j=0;j<i;j++)
				printf("%d",a[j]);
			if(t==1) printf(" is not cyclic\n");
			else printf(" is cyclic\n");
		}
	}
	return 0;
}



