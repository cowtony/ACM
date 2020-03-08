#include <iostream>
using namespace std;

int main()
{
	long long a[21][201];
	int i,j,k,n;
	a[1][0]=1;
	for(i=1; i<201; i++)
	{
		a[1][i]=0;
		if(i<=20) a[i][0]=1;
	}
	
	for(i=2; i<=20; i++)
	{
		for(j=1; j<201; j++)
		{
			if(j>=i)
			{
				a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-i];
			}
			else a[i][j]=a[i-1][j]+a[i][j-1];
		}
	}
	while(cin>>n>>k)
	{
		if(!n&&!k) break;
		cout<<a[n][k]<<endl;
	}
	return 0;
}
