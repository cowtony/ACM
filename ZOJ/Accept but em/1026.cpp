 //80680 2003-03-01 13:15:47 Accepted 1026 C++ 00:00.11 520K Century Ghost
 #include<iostream.h>

 const int max=2001;
 struct poly
 {
	int point;
	int num[max];
 };

 void mul(poly f,poly g,poly& temp)
 {
	temp.point=f.point+g.point-1;
	int i,j;
	for(i=temp.point-1;i>=0;i--)	temp.num[i]=0;
	for(i=f.point-1;i>=0;i--)
		for(j=g.point-1;j>=0;j--)
			temp.num[i+j]+=f.num[i]*g.num[j];
	j=temp.point-1;
	for(i=j;i>=0;i--)
	{
		temp.num[i]%=2;
		if(i==temp.point-1&&temp.num[i]==0)	temp.point--;
	}
 }
 void sub(poly f,poly g,poly& result)
 {
	int i;result.point=f.point;
	for(i=f.point-1;i>=0;i--)
		result.num[i]=f.num[i]-g.num[i];
	int t=f.point-1;
	for(i=t;i>=0;i--)
	{
		if(result.num[i]==-1)	result.num[i]=1;
		if(i==result.point-1&&result.num[i]==0)	result.point--;
	}
 }

 void div(poly f,poly g,poly& result)
 {
	poly temp;poly middle;int i;
	while(1)
	{
		if(f.point<g.point)	break;
		middle.point=f.point;
		int tt=f.point-g.point;
		for(i=g.point-1;i>=0;i--)
			middle.num[i+tt]=g.num[i];
		for(i=tt-1;i>=0;i--)	middle.num[i]=0;
		sub(f,middle,temp);
		f.point=temp.point;
		for(i=temp.point-1;i>=0;i--)    f.num[i]=temp.num[i];
	}
	result.point=f.point;
	for(i=f.point-1;i>=0;i--)	result.num[i]=f.num[i];
 }





 int main()
 {
	int n;
	cin>>n;
	while(n--)
	{
		poly f,g,h;int i;
		cin>>f.point;
		for(i=f.point-1;i>=0;i--)	cin>>f.num[i];
		cin>>g.point;
		for(i=g.point-1;i>=0;i--)	cin>>g.num[i];
		cin>>h.point;
		for(i=h.point-1;i>=0;i--)	cin>>h.num[i];
		poly temp;
		mul(f,g,temp);
		poly result;
		div(temp,h,result);
		cout<<result.point;
		for(i=result.point-1;i>=0;i--)	cout<<" "<<result.num[i];
		cout<<endl;
	}
	return 0;
 }



