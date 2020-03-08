#include <stdio.h>
#include <string.h>
int main()
{
	int a[1200];
	int n;
	char p2[21];
	char str2[6];
	char str[1200][21];
	int i,j,k=0,l=0,t,p,p3;
	while(scanf("%s",str2)!=EOF)
	{
		while(1)
		{
			scanf("%s",str[l]);
			if(strcmp(str[l],"END")==0) {a[l]=0;l++;break;}
			scanf("%d%d",&n,&a[l]);
			a[l]-=n;
			l++;
		}
	}
	t=0;
	while(t<l)
	{
		p3=0;
		for(i=t;a[i+1]!=0;i++)
		{
			for(j=i+1;a[j]!=0;j++)
			{
				p3=1;
				if(a[i]<a[j])
				{
					p=a[i];
					a[i]=a[j];
					a[j]=p;
					strcpy(p2,str[i]);
					strcpy(str[i],str[j]);
					strcpy(str[j],p2);
				}
			}
		}
		if(p3==0) t+=2;
		else t=j+1;
	}
	for(i=0;i<l-1;i++)
	{
		if(a[i]==0&&i<l-1) printf("\n");
		else printf("%s\n",str[i]);
	}
	return 0;
}




