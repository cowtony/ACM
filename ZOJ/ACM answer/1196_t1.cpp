 #include<iostream.h>

 long pos[201];
 long make(int beg,int end, int lev)
 {

	if(end-beg+1<=lev)	return 0;
	if(lev==1)
	{       int mid;int i;long sum=0;
		if((end-beg)%2==0)
			mid=beg+(end-beg)/2;
		else	mid=beg+(end-beg-1)/2;
		for(i=beg;i<mid;i++)
			sum+=pos[mid]-pos[i];
		for(i=mid+1;i<=end;i++)
			sum+=pos[i]-pos[mid];
		return sum;
	}
	long min=-1;int i;
	for(i=beg;i<=end;i++)
	{
		long temp=make(beg,i,1)+make(i+1,end,lev-1);
		if(min==-1)	min=temp;
		else if(min>temp)	min=temp;
	}
	return min;
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
		long min;
		min=make(0,n-1,k);

		cout<<"Total distance sum = "<<min<<endl;
		cout<<endl;
	}
	return 0;
 }






