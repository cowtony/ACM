#include <iostream>
using namespace std;

int main()
{
	int city;
	int i,j;
	int a[10000][2];
	while(scanf("%d",&city)!=EOF)
	{
		for(i=0;i<city;i++)
		{
			scanf("%d%d",&a[i][0],&a[i][1]);
		}
		int t=0;
		for(i=0;i<city;i++)
		{
			int temp=0;
			int t1=0;
			for(j=i;j<city;j++)
			{
				temp+=(a[j][0]-a[j][1]);
				if(temp<0)
				{
					t1=1;
					break;
				}
			}
			if(!t1)
			{
				for(j=0;j<=i;j++)
				{
					temp+=(a[j][0]-a[j][1]);
					if(temp<0)
					{
						t1=1;
						break;
					}
				}
			}
			if(t1) continue;
			else {t=1;break;}
		}
		if(t) printf("%d\n",i);
		else printf("impossible\n");
	}
	return 0;
}




