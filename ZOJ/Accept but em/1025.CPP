 #include<iostream.h>

 void bubble(int a[],int b[],int n)
 {
	int i,j;
	for(i=0;i<n;i++)
	{
		int temp=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[temp]||(a[j]==a[temp]&&b[j]<b[temp]))	temp=j;
		int t=a[i];a[i]=a[temp];a[temp]=t;
		t=b[i];b[i]=b[temp];b[temp]=t;
	}
 }


 int main()
 {
	int nn;
	cin>>nn;int i,j;
	for(i=1;i<=nn;i++)
	{
		int n;
		cin>>n;
		int a[5001];int b[5001];int flag[5001];
		for(j=0;j<n;j++)	cin>>a[j]>>b[j];
		bubble(a,b,n);


		for(j=0;j<n;j++)	flag[j]=0;
		int minute=0;
		for(j=0;j<n;j++)
		{
			if(flag[j]) continue;
			flag[j]=1;
			minute++;
			int tempa=a[j];int tempb=b[j];
			int t;
			for(t=j+1;t<n;t++)
			{
				if(flag[t]) continue;
				if(a[t]>=tempa&&b[t]>=tempb)
				{
					tempa=a[t];tempb=b[t];
					flag[t]=1;
				}
			}
		}
		cout<<minute<<endl;
	}
	return 0;
 }

