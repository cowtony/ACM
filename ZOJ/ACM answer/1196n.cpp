 #include<iostream.h>

 int pos[201];
 int cal(int beg,int end)
 {
	int sum=0;
	while(beg<end)	sum+=pos[end--]-pos[beg++];
	return sum;
 }
 int main()
 {
	int n,k;int count=0;
	while(1)
	{
		cin>>n>>k;
		if(n==0&&k==0)	break;
		int i,j;int d,t;
		for(i=0;i<n;i++)	cin>>pos[i];
		count++;
		cout<<"Chain "<<count<<endl;
		if(n<=k)
		{
			cout<<"Total distance sum = 0"<<endl<<endl;
			continue;
		}

		int val[201][32];
		for(i=0;i<n;i++)
				for(t=0;t<=k;t++)	val[i][k]=0;
		for(i=0;i<n;i++)
			val[i][1]=cal(i,n-1);
		for(t=2;t<=k;t++)
		{
			for(i=0;i<n;i++)
			{	int min=-1;
				for(j=i;j<n-t+1;j++)
				{
					int temp=cal(i,j)+val[j+1][t-1];
					if(min==-1)	min=temp;
					else  if(min>temp)	min=temp;
				}
				if(min==-1)	min=0;
				val[i][t]=min;
			}
		}
		cout<<"Total distance sum = "<<val[0][k]<<endl;
		cout<<endl;
	}
	return 0;
 }






