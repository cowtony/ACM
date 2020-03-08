#include <iostream.h>
#include <string.h>
int main()
{
	char a[1000][17];
	float b[1000];
	char s[40];
	float money;
	int i;
	int m,n;
	cin>>m>>n;
	for(i=0;i<m;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	while(n--)
	{
		money=0;
		while(cin>>s&&strcmp(s,".")!=0)
		{
			for(i=0;i<m;i++)
			{
				if(strcmp(s,a[i])==0) money+=b[i];
			}
		}
		cout<<money<<endl;
	}
	return 0;
}
