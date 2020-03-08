//program p1074;
#include<iostream.h>
int main()
{
	int max,n,i,j,ni,nj,xi,yj,t,s;
	int a[110][110];
	max=0;
	cin>>n;
  for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
      cin>>a[i][j];
	for (ni=1;ni<=n;ni++)
		for (nj=1;nj<=n;nj++)
			for (i=1;i<=n-ni+1;i++)
				for (j=1;j<=n-nj+1;j++)
				{
					t=1;s=0;
					for (xi=i;xi<=i+ni-1;xi++)
					{
						for (yj=j;yj<=j+nj-1;yj++)
						{
							if (a[xi][yj]==0) {t=0;break;}
							s+=a[xi][yj];
						}
						if (t==0) break;
					}
					if (t==1&&s>max) max=s;
				}
	cout<<max<<endl;
	return 0;
}