 #include<iostream.h>

 double ppp(int n,int m)
 {
	double re_val=1;
	for(int i=n;i>=n-m+1;i--)	re_val*=i;
	return re_val;
 }

 double ccc(int n,int m)
 {
	double re_val=1;
	for(int i=n;i>=n-m+1;i--)	re_val*=i;
	return re_val/ppp(m,m);
 }


 int main()
 {
	long n;
	while(cin>>n)
	{
		int a[13];
		int input;int i;
		int sum=0;
		for(i=1;i<=12;i++)	a[i]=0;
		for(i=1;i<=n;i++)
		{
			cin>>input;
			sum+=input;
			a[input]++;
		}
		double way=1;
		for(i=1;i<=12;i++)
		{
			if(a[i]==0)	continue;
			int temp=a[i]*i;
			double t_res=1;
			for(int j=1;j<=a[i];j++)
			{
				t_res*=ccc(temp,i);
				temp-=i;
			}
			way*=ccc(sum,a[i]*i)*t_res/ppp(a[i],a[i]);
			sum-=a[i]*i;
		}
		cout<<way<<endl;
	}
	return 0;
 }
