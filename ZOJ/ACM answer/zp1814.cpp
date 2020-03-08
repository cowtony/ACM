#include <iostream.h>

int main()
{
	int a[10010],b[10010];
	int n,s,t,i;
	cin>>n;
	while (n)
	{
		for (i=0;i<n;i++)
		   cin>>a[i];
		s=0;
		while (1)
		{
			t=1;
			for (i=1;i<n;i++)
			   if (a[i]!=a[i-1]) t=0;
			if (t) break;
			s++;
			for (i=0;i<n;i++)
			   a[i]/=2;
			for (i=0;i<n;i++)
			   b[i+1]=a[i];
			for (i=1;i<n;i++)
			   a[i]+=b[i];
			a[0]+=b[n];

			for (i=0;i<n;i++)
			   if (a[i]%2) a[i]++;
		}
		cout<<s<<' '<<a[0]<<endl;
		cin>>n;
	}
	return 0;
}
