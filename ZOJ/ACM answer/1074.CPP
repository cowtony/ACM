 #include<iostream.h>
 long max(int n,long a[])
 {
	int i;
	long sum=a[0];
	long tempsum=a[0];
	for(i=1;i<n;i++)
	{
		if(tempsum>0)
			tempsum+=a[i];
		else tempsum=a[i];
		if(tempsum>sum) sum=tempsum;
	}
	return sum;
 }

 int main()
 {
	int n;int i,j;
	int a[101][101];
	cin>>n;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)	cin>>a[i][j];
	int k;
	long sum=a[0][0];
	long b[101];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)	b[j]=a[i][j];

		long temp=max(n,b);
		if(temp>sum) sum=temp;

		for(j=i+1;j<n;j++)
		{
			for(k=0;k<n;k++)	b[k]+=a[j][k];
			long temp=max(n,b);
			if(temp>sum) sum=temp;
		}
	}
	cout<<sum<<endl;
	return 0;
 }


