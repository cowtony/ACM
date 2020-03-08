#include <iostream>
int main()
{
	int a[49][49];
	int b[1176];
	int i,j,k;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",n*(n-1)/2);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		b[0]=0;
		b[1]=1;
		b[n*(n-1)/2-1]=n-1;
		a[0][1]=a[1][0]=1;
		a[0][n-1]=a[n-1][0]=1;
		for(j=1;j<n*(n-1)/2-1;j++)
		{
			for(k=0;k<n;k++)
			{
				if(!a[b[j]][k]&&b[j]!=k)
				{
					b[j+1]=k;
					a[b[j]][k]=a[k][b[j]]=1;
					break;
				}
			}
		}
		printf("%d",b[0]);
		for(i=1;i<n*(n-1)/2;i++)
		{
			printf(" %d",b[i]);
		}
		printf("\n");
	}
	return 0;
}

