#include <stdio.h>
int a[1500][1500];
int count[1500];

int main()
{
	int i,j,k;
	int th,son,sonnum;
	int n;
	int result,t;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j]=0;
			}
			count[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d:(%d)",&th,&son);
			for(j=0;j<son;j++)
			{
				scanf("%d",&sonnum);
				a[th][sonnum]=a[sonnum][th]=1;
				count[th]++;
				count[sonnum]++;
			}

		}
		result=0;
		while(1)
		{
			t=0;
			for(i=0;i<n;i++)
			{
				if(count[i]==1)
				{
					t=1;
					result++;
					for(j=0;j<n;j++)
					{
						if(a[i][j])
						{
							for(k=0;k<n;k++)
							{
								if(a[j][k])
								{
									a[j][k]=a[k][j]=0;
									count[j]--;
									count[k]--;
								}
							}
						}
					}
				}
			}
			if(!t) break;
		}
		printf("%d\n",result);
	}
	return 0;
}
			




