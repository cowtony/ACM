 #include<iostream.h>

 float cal_area(int m,int x[],int y[])
 {
	float area;
	area=y[0]*(x[m-1]-x[1]);
	for(int i=1;i<m;i++)
		area+=y[i]*(x[i-1]-x[(i+1)%m]);
	return (area/2);
 }

 int gcd(int first,int second)
 {
	if(second==0) return first;
	return gcd(second,first%second);
 }


 int main()
 {
	int nn;int i;
	cin>>nn;
	for(i=1;i<=nn;i++)
	{
		int x[101];int y[101];
		int a[101];int b[101];
		int m;int j;
		cin>>m;
		for(j=0;j<m;j++)	cin>>a[j]>>b[j];
		x[0]=0;y[0]=0;
		for(j=1;j<m;j++)
		{
		      x[j]=x[j-1]+a[j-1];
		      y[j]=y[j-1]+b[j-1];
		}
		float area=cal_area(m,x,y);
		int total_grid=m;
		for(j=0;j<m;j++)
		{       int temp_x=a[j];
			int temp_y=b[j];
			if(temp_x<0) temp_x=-temp_x;
			if(temp_y<0) temp_y=-temp_y;
			int temp;

			if(temp_x==0) temp=temp_y;
			else if(temp_y==0) temp=temp_x;
			else temp=gcd(temp_x,temp_y);

			total_grid+=temp-1;
		}
		int ini_grid=area+1-total_grid*1.0/2;
		cout<<"Scenario #"<<i<<":"<<endl;
		cout<<ini_grid<<" "<<total_grid<<" ";
		cout.precision(1);
		cout.setf(ios::showpoint|ios::fixed);
		cout<<area<<endl<<endl;
	}
	return 0;
 }

