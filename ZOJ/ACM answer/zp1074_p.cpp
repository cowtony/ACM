#include <iostream>
using namespace std;
int t[101][101];
int main()
{
	int n,p[101],max(0),sum(0);
	for(int i=0;i<101;i++)
	{
    t[i][0]=0;
	  t[0][i]=0;
	}
  while(cin>>n)
	{
		max=0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
			{
				cin>>t[i][j];
        t[i][j]+=t[i-1][j];
			}
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
			{
				sum=0;
				for(int k = 1; k <= n; k++)
					p[k] =t[j][k]-t[i-1][k];
				for(int m = 1; m <= n; m++)
				{
					if(sum+p[m]>=0)
					{
						sum+=p[m];
						if(sum>=max)  max=sum;
          }
					else sum=0;
				}
			}
		cout << max << endl;
	}
	return 0;
}
