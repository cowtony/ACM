 #include<iostream.h>

 void bubble(long a[],long b[],int n,int old[])
 {
	int i,j;
	for(i=0;i<n;i++)
	{
		int temp=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[temp]||(a[j]==a[temp]&&b[j]<b[temp]))	temp=j;
		int t=a[i];a[i]=a[temp];a[temp]=t;
		t=b[i];b[i]=b[temp];b[temp]=t;
		t=old[i];old[i]=old[temp];old[temp]=t;
	}
 }


 int main()
 {
	while(1)
	{
		long a[1001];long b[1001];
		int pre[1001];int add[1001];int old[1001];
		int n;int i,j;
		cin>>n;
		if(n==0) break;
		for(i=0;i<n;i++)	cin>>a[i]>>b[i];
		for(i=0;i<n;i++)	old[i]=i;
		bubble(a,b,n,old);
		for(i=0;i<n;i++)	pre[i]=-1;
		for(i=0;i<n;i++)	add[i]=1;
		for(i=0;i<n;i++)
		{
			int sum=0;int pt=0;
			for(j=0;j<i;j++)
			{
				if(b[j]>=a[i]) continue;
				if(add[j]>sum) {sum=add[j];pt=j;}
			}
			if(sum!=0){	add[i]=sum+1;pre[i]=pt;}
		}
		int sum=0;int pt=0;
		for(i=0;i<n;i++)
			if(add[i]>sum)  pt=i;
		int tt[1001];int temp=0;
		while(pt!=-1)
		{
		      tt[temp++]=pt;
		      pt=pre[pt];
		}

		for(i=temp-1;i>=0;i--)
		{
			cout<<(old[tt[i]]+1);
			if(i!=0) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
 }
