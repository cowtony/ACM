//program p1016;
#include<iostream.h>
int main()
{
	int nn,nnn,n,i,j,s,u,l,k;
  int p[25],w[25],a[1000];

	cin>>nn;
	for (nnn=1;nnn<=nn;nnn++)
	{
		cin>>n;
		for (i=1;i<=n;i++)
			cin>>p[i];
		p[0]=0;s=0;
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=(p[i]-p[i-1]);j++)
			{
				s+=1;
				a[s]=0;
			}
			s+=1;
			a[s]=1;
		}

		u=0;
		for (i=1;i<=s;i++)
			if (a[i]==1) 
			{
				u+=1;k=0;l=0;
				for (j=i;j>=1;j--)
				{
					if (a[j]==1) k-=1; else {k+=1;l+=1;}
					if (k==0) break;
				}
				w[u]=l;
			}
		cout<<w[1];
		for (i=2;i<=n;i++)
			cout<<' '<<w[i];
		cout<<endl;
	}
	return 0;
}
//		for (i=1;i<=s;i++)
//			if (a[i]==0) cout<<'('; else cout<<')';