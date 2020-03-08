 #include<iostream.h>
 #include<math.h>


 struct point
 {	double x,y;
 };
 struct line
 {	point a,b;
 };

 double cal_area(point polygon[],int n)
 {
	double area=0;
	area=polygon[0].y*(polygon[n-1].x-polygon[1].x);
	for(int i=1;i<n;i++)
		area+=polygon[i].y*(polygon[i-1].x-polygon[(i+1)%n].x);

	return fabs(area/2.0);
 }

 double max(double a,double b)
 {
	return ((a>b)?a:b);
 }
 double min(double a,double b)
 {
	return ((a>b)?b:a);
 }
 double multiply(point fir,point sec,point thi)
 {
	return ((fir.x-thi.x)*(sec.y-thi.y)-(sec.x-thi.x)*(fir.y-thi.y));
 }
 int intersect(line fir,line sec)
 {
	return ((max(fir.a.x,fir.b.x)>=min(sec.a.x,sec.b.x))&&
		(max(fir.a.y,fir.b.y)>=min(sec.a.y,sec.b.y))&&
		(max(sec.a.x,sec.b.x)>=min(fir.a.x,fir.b.x))&&
		(max(sec.a.y,sec.b.y)>=min(fir.a.y,fir.b.y))&&
		(multiply(fir.a,sec.a,sec.b)*multiply(sec.a,fir.b,sec.b)>=0)&&
		(multiply(sec.b,fir.a,fir.b)*multiply(fir.a,sec.a,fir.b)>=0)
	       );
 }
 int is_possible(point polygon[],int n)
 {
	int i,j;
	for(i=0;i<n-2;i++)
		for(j=i+2;j<n;j++)
		{
			if(i==0&&j==n-1) continue;
			line fir,sec;
			fir.a=polygon[i];fir.b=polygon[i+1];
			sec.a=polygon[j];sec.b=polygon[(j+1)%n];
			if(intersect(fir,sec)) return 0;
		}
	return 1;
 }


 int main()
 {
	int n;int flag=0;
	while(1)
	{
		cin>>n;
		if(n==0) break;
		if(flag) cout<<endl;
		flag++;
		point polygon[1001];int i,j;
		for(i=0;i<n;i++)	cin>>polygon[i].x>>polygon[i].y;
		cout<<"Figure "<<flag<<": ";
		if(n<3){cout<<"Impossible"<<endl;continue;}
		int possible=is_possible(polygon,n);
		double area;
		if(possible)   area=cal_area(polygon,n);

		if(possible)
		{	cout.setf(ios::fixed|ios::showpoint);
			cout.precision(2);

			cout<<area<<endl;
		}else cout<<"Impossible"<<endl;
	}
	return 0;
 }

