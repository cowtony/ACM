//program p1202;
#include<iostream.h>
int func(int m,int n)
{
	int sum=1,i;
	for (i=n+1;i<=m;i++)
		sum*=i;
	for (i=2;i<=m-n;i++)
		sum/=i;
	return sum;
}
int main()
{
	int w,s,j,i,n;
	int a[15],g[15];
	while (cin>>n)
	{
		w=1;
		for (i=1;i<=n;i++)
			cin>>a[i];
		for (i=1;i<n;i++)
			for (j=i+1;j<=n;j++)
				if (a[i]<a[j]) 
				{
					s=a[i];a[i]=a[j];a[j]=s;
				}
		s=0;
		for (i=1;i<=n;i++)
			s+=a[i];
		for (i=1;i<=n;i++)
		{
			w*=func(s,a[i]);
			s-=a[i];
		}
		for (i=1;i<=a[1];i++)
			g[i]=0;
		for (i=1;i<=n;i++)
			g[a[i]]+=1;
		for (i=1;i<=a[1];i++)
			if (g[i]>1) 
				for (j=2;j<=g[i];j++)
					w/=j;
		cout<<w<<endl;
	}
	return 0;
}