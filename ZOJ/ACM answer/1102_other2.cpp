 #include<iostream.h>

 int main()
 {
	int val[1001][26];
	int n,l;
	while(1)
	{
		cin>>n>>l;
		if(n==0&&l==0)	break;
		int i,j;char ch;
		for(i=1;i<=l;i++)
			for(j=0;j<26;j++)	val[i][j]=0;

		for(i=1;i<=n;i++)
		{
			for(j=1;j<=l;j++)
			{
				cin>>ch;
				val[j][ch-65]++;
			}
		}
		long sum=0;
		for(i=1;i<=l;i++)
		{
			sum+=(long)val[i][25];
			int max=val[i][25];int pt=0;
			for(j=24;j>=0;j--)
			{
				if(val[i][j]>max){pt=j;max=val[i][j];}
				sum+=(long)val[i][j];
			}
			sum-=(long)max;
			cout<<char(pt+65);
		}

		cout<<" "<<sum<<endl;

	}
	return 0;
 }




